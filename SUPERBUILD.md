# Lichii Superbuild (unofficial)

## Credits

This build exists because of the work of:

- [zortos293/Lichii](https://github.com/zortos293/Lichii) — base `nx2`, compatibility reports, first-run performance defaults, Bananza page-mark batching, perf9 paths
- [jojo-chaechae/Eglantine](https://github.com/jojo-chaechae/Eglantine) — GPU-split submit and macro hand-back fixes
- [Duck912/Eglantine-ducky](https://github.com/Duck912/Eglantine-ducky) — OoT reticle/CPU-write fix and near-leaf pointer fix
- [Frizti/Lichii](https://github.com/Frizti/Lichii) — scoped buffer/submission/FSR3 fixes and Dynamic FPS
- [mja00/Lichii](https://github.com/mja00/Lichii) — uniform-bank upload, query timing, HMMA unroll
- [Nolar-Hack/Lichii](https://github.com/Nolar-Hack/Lichii) — video swap-interval, compute sizing, scheduler exclusion, guest RAM release, texture-cache threshold
- [BrunoSilvestre00](https://github.com/BrunoSilvestre00) — async native draw discard (PR #224)
- [Shakoquo/Lichii-sharkiix-version](https://github.com/Shakoquo/Lichii-sharkiix-version) — GPU thread wake and AMD/OoT tuning experiments
- The Eglantine, Eden, yuzu and Sudachi contributors

Curated performance and correctness fixes on top of
[zortos293/Lichii](https://github.com/zortos293/Lichii) `nx2`.

This is **not** an official Lichii build. It is a testing branch that combines
selected upstream and fork fixes with explicit provenance. Expect breakage; keep
a stock build as fallback.

## Base

- Upstream: `zortos293/Lichii`
- Branch: `nx2`
- Base commit: `71268a75e806a92f55c21f2577aaa19c6e9d6692` (2026-11-07) plus
  `capy/oot-hyrule-grass-fix` (`dfde7585e2`, 14 commits)
- Upstream `nx2` already contains #303, #287, #314, #224, #273, #284, #290,
  #295, #149, #185, #197, #203, #215, #232, #241, #397, #398, #410, #412,
  #413, #414, #418, #425, #429, #433, #435, #438, #439, #442, #443, #444,
  #482, #485, #490, #432 (NaN min/max), #436 (QMD release formats), #351
  (table-pointer pool binding), #504 (updater), #255/#497 (microphone),
  #499 (NUP metadata), plus #512 (device-loss diagnostics), #515 (mesh
  point/line output), #518/#519/#526 (clang-cl ThinLTO release builds),
  #524 (`-fno-unswitch-loops`), #537 (frame-generation status), #509
  (in-place AppImage updater with rollback) and #520 (clang-cl build-check CI).
  Those are not re-applied here.
- License: GPL-3.0-or-later, inherited from Lichii/Eden/yuzu

## Branches

- `nx2` — untouched upstream snapshot used as the base
- `superbuild` — current curated build, including all portable fixes

This repository is a standalone public mirror, not a GitHub fork-network fork.
There is no separate AMD variant.

## Releases

Standard and PGO builds are published for Windows and Linux x86_64. PGO is the
recommended package. The PGO profile is `eglantine.profdata`, built with Clang 23
and LLD, using bundled static FFmpeg to avoid the MSYS2 `libva.dll` false
positive.

The updater points at this repository's releases (`callme-sy/Lichii-Superbuild`,
`vN` tags, `Lichii-vN-<platform>` assets). It is enabled in release builds only when
`LICHII_BUILD_TAG` and `LICHII_BUILD_PLATFORM` are set at configure time.

## OoT Hyrule Field grass fix

The 14-commit `capy/oot-hyrule-grass-fix` branch (`dfde7585e2`) is carried in
full. It is zortos's integration of the open fix chain PR #434 / #395 / #421:

- `MAX_SSBOS` goes from 32 to 64, with 64-bit storage binding masks, so the
  foliage culling computes keep all per-type instance tables bound and Hyrule
  Field's grass is no longer culled wholesale.
- Compute translations whose pointer slots were null at translation are rebuilt
  once those slots hold mapped pointers, and a rebuild keeps every pointer the
  old translation bound. Castle Town's near hedges keep their leaves.
- Replaced pipelines are retired only once the GPU and queued builds are done.
- Storage buffer counts are capped by the device's per-stage and descriptor-set
  limits so a program that reads too many pointers is rejected cleanly.

The earlier `capy/oot-hyrule-grass-ab` A/B experiment was dropped: with the fix
present there is nothing left to bisect, and its off-by-default switches are not
shipped. The fix is still unmerged into `nx2`; when zortos lands it upstream, we
will rebase and drop these commits.

## Included fixes

### From zortos293/Lichii and forks

| Fix | Source |
|---|---|
| Bananza GPU-written page marks batched by bitmap word | zortos `perf/bananza-perf9`, `dd8e60ef` |
| Upload native 64 KiB uniform banks without protection churn | mja00 `fix/native-uniform-bank-upload`, `dbcbe547` |
| Write fence-flagged query reports after prior GPU work | mja00 `fix/fence-query-report-timing`, `0059f37b` |
| Unroll each K8 group of the software HMMA | mja00 `fix/hmma-k8-group-unroll`, `7221023e` |
| Do not download GPU data over newer CPU writes (OoT reticle) | Duck912, `05fe0408` |
| Submit deferred work before the split back waits on fences | GPU-split branch, `498345a5` |
| Hand macros back when the GPU split stops | GPU-split branch, `5b1b5c0f`, conflict resolved |
| Wake the GPU thread on a queued command | Shakoquo `sharkiix`, `28f594acc7` |
| OoT recommended settings prompt (session-only) | superbuild UI, `capy/new-user-performance-defaults` values |

### Additional portable fixes

| Fix | Source |
|---|---|
| Lift `EDEN_NX2_SWAP_INTERVAL` while a video plays | Nolar-Hack `oot-amd-linux`, `1ae67a43` |
| Size native compute storage buffers from the mapping only for DLSS/tables | Nolar-Hack, `3472a85a` |
| Keep other threads out of the Vulkan scheduler during split-back submit | Nolar-Hack, `b39883d2` |
| Release guest RAM when a Switch 2 game stops | Nolar-Hack, `30e3cc38` |
| `EDEN_NX2_TC_MINIMUM_MIB` texture-cache collection threshold | Nolar-Hack, `52504537` |

Upstream #273 already fixes the depth-compare integer case on AMD; the earlier
mja00 `be437dd4` and Nolar `63650298` variants are not re-applied on top of it.

## Deliberately not included

- mja00 storage-binding range cache (`2aea767b`) — conflicts with newer
  memory-manager code; needs a rebase.
- GPU-split overlapping-write wait (`add0db8c`) — conflicts with the newer
  query/drain path.
- Nolar ARM64 dynarmic superblock work — irrelevant on x86_64.
- Nolar tools/docs/fork-notice commits.
- Auto-stub debug logging.
- Unrelated forks and experimental branches.

## Environment switches

- `EDEN_NX2_PRELOAD_ALL_PIPELINES=1` is preset in the packaged
  `nx2_switches.txt`.
- `EDEN_NX2_ASYNC_DISCARD=1` is preset; native draws skip unbuilt pipelines
  instead of stalling (experimental, from PR #224).
- `EDEN_NX2_COMPUTE_MAPPING_SIZED=1` restores the old compute-buffer sizing for
  A/B testing of the OoT overexposure candidate.
- `EDEN_NX2_TC_MINIMUM_MIB` controls the texture-cache collection threshold.

## Building

The build is a normal Lichii PGO build. Set `<repo>` to the checkout, `<msys2>`
to the MSYS2 UCRT64 root, and `<qt>` to the Qt 6 prefix.

Windows (MSYS2 UCRT64, Clang 23):

```bash
cmake -S <repo> -B <repo>/build/pgo -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DYUZU_CMD=ON -DYUZU_ROOM=OFF \
  -DYUZU_USE_BUNDLED_QT=OFF -DYUZU_USE_BUNDLED_SDL3=ON \
  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_EXE_LINKER_FLAGS=-fuse-ld=lld \
  "-DCMAKE_C_FLAGS=-fprofile-use=<repo>/eglantine.profdata -Wno-backend-plugin -Wno-profile-instr-unprofiled -Wno-profile-instr-out-of-date" \
  "-DCMAKE_CXX_FLAGS=-fprofile-use=<repo>/eglantine.profdata -Wno-backend-plugin -Wno-profile-instr-unprofiled -Wno-profile-instr-out-of-date"
cmake --build <repo>/build/pgo --target yuzu yuzu-cmd --parallel 8
```

Linux (Clang 23 + LLD, Qt 6.8.3):

```bash
cmake -S <repo> -B <repo>/build/pgo -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DYUZU_CMD=ON -DYUZU_ROOM=OFF \
  -DYUZU_USE_BUNDLED_QT=OFF -DCMAKE_PREFIX_PATH=<qt> \
  -DYUZU_USE_BUNDLED_SDL3=ON -Dfmt_FORCE_BUNDLED=ON \
  -DCMAKE_C_COMPILER=clang-23 -DCMAKE_CXX_COMPILER=clang++-23 \
  "-DCMAKE_EXE_LINKER_FLAGS=-B/usr/lib/llvm-23/bin -fuse-ld=lld" \
  "-DCMAKE_C_FLAGS=-fprofile-use=<repo>/eglantine.profdata -Wno-backend-plugin -Wno-profile-instr-unprofiled -Wno-profile-instr-out-of-date" \
  "-DCMAKE_CXX_FLAGS=-fprofile-use=<repo>/eglantine.profdata -Wno-backend-plugin -Wno-profile-instr-unprofiled -Wno-profile-instr-out-of-date"
cmake --build <repo>/build/pgo --target yuzu yuzu-cmd --parallel 8
```

See `tools/superbuild/README.md` for packaging notes.

## Reproducing the patch

`patches/superbuild.patch` is the complete diff from the base commit to
`superbuild`.

```bash
git checkout 71268a75
git apply patches/superbuild.patch
```
