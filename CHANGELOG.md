# Changelog

All releases are unofficial builds. See the GitHub releases for assets and
checksums.

## v14

- Base: `nx2` `33acb0e1a` — a 24-commit upstream batch. The grass/foliage fix
  is now upstream as #551, so our 14 carried `capy/oot-hyrule-grass-fix`
  commits were dropped along with the texture-cache OOM, framebuffer-limit,
  GPU-thread-wake and HMMA-unroll commits that upstream absorbed (#440, #427,
  #446, #174). Our superbuild layer is now much smaller.
- New upstream: #588 TXD/ATOMG shadow registers, #584 Dynamic FPS down to
  10 fps, #585 sysmix audio, #580 page-table walk reuse, #550 disk-cache
  pipelines, #465 bounded unbuilt-pipeline wait, #333 page-table sizing,
  #481 sorted RangeSet, #250 skip empty invalidations, #245 bindless handle
  words, #495 descriptor payload growth, #530 Linux core pinning, #270
  present FPS limit, #365 Overwolf hook disable, #484 maximized window,
  #511 MIME install, #160 ZBIC failure, #221 IPSwitch lines.
- Keeps our unique layer: OoT recommended-settings prompt, GPU-split
  scheduler/fence fixes, query-cache fence-flagged reports, texture-cache
  minimum threshold, `EDEN_NX2_PRELOAD_ALL_PIPELINES` and
  `EDEN_NX2_ASYNC_DISCARD` presets, and the updater wired to this repository.
- Windows and Linux, standard and PGO, bundled static FFmpeg on Windows.

## v13

- Base: `nx2` `71268a75` — upstream #509 in-place AppImage updater with one
  rollback copy, and #520 clang-cl build-check CI.
- **OoT Hyrule Field grass fixed.** Carries all 14 commits of zortos's
  `capy/oot-hyrule-grass-fix` (`dfde7585e2`), the integration of open fix chain
  PR #434 / #395 / #421: 64 storage buffers per stage, 64-bit binding masks,
  rebuild of compute translations whose null pointer slots fill later, keeping
  every previously bound pointer on rebuild, and per-stage storage limits.
  Castle Town's near hedges keep their leaves and Hyrule Field's grass stays
  dense. The branch is still unmerged into `nx2`.
- Dropped the v12 `capy/oot-hyrule-grass-ab` A/B experiment: with the fix in
  place there is nothing left to bisect.
- Updater still points at this repository (`vN` tags), now with in-place
  AppImage update support from #509.
- Windows and Linux, standard and PGO, bundled static FFmpeg on Windows.

## v12

- Base: `nx2` `91d1aada` — upstream #512 device-loss diagnostics, #515 mesh
  point/line output, #518/#519/#526 clang-cl ThinLTO release builds,
  #524 `-fno-unswitch-loops` and #537 frame-generation status.
- Updater now points at this repository: `callme-sy/Lichii-Superbuild`, `vN`
  tags and `Lichii-vN-<platform>` assets.
- Carries `capy/oot-hyrule-grass-ab` A/B diagnostics for the OoT Hyrule Field
  grass regression. Four off-by-default switches, no change to stock behaviour;
  the full fix remains open upstream as PR #434.
- Both Windows packages use bundled static FFmpeg.
- Keeps the OoT recommended-settings prompt, GPU thread wake and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## v11

- Base: `nx2` `32886f75` — upstream #351 table-pointer pool binding, #432
  NaN min/max, #436 QMD release formats, #504 updater, #255/#497 microphone
  capture and #499 NUP metadata.
- Both Windows packages now use bundled static FFmpeg, removing the MSYS2
  `libva.dll` false positive.
- Keeps the OoT recommended-settings prompt, GPU thread wake and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## v10

- Base: `nx2` `412c753b` — a 43-commit upstream batch including #425 64-byte
  usage tracking, #429 32-bit global atomics, #433 dynamic per-tap offsets,
  #438 macro hand-back, #439 Turing macro RAM, #444 gathered-buffer lifetime,
  #435 address-wrap rejection, #443/#442 game-list fixes and #418 core pinning.
- Keeps the v9 candidate fixes that remain unmerged.
- Keeps the OoT recommended-settings prompt, GPU thread wake and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## 261106-v9

- Base: `nx2` `9fa4a71` (unchanged from v8).
- Adds reviewed `capy/*` fixes: NaN-defined shader min/max/clamp, QMD release
  formats, framebuffer and stream-buffer limits, texture-cache OOM retries,
  texture-cache debug stats off, and mesh-shader skip logging.
- Keeps the OoT recommended-settings prompt, GPU thread wake and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## 261106-v8

- Base: `nx2` `9fa4a71` — upstream #149 (OoT split deadlock/FSR3/RED-SURED),
  #412 (GPU back bookkeeping), #414 (quad index growth), #413 (lock-free flush
  check), #410 (paired cbuf pointer), #215 (query waits), #197, #241, #398,
  #185, #203, #397 (CPU-write guard) and #232 (hybrid CPU cores).
- Keeps the OoT recommended-settings prompt, GPU thread wake and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## 261106-v7

- Base: `nx2` `4c173bb7` — upstream #303 opt-in desktop compatibility reports
  and #287 Linux AppImage switch discovery, plus all earlier upstream fixes.
- Keeps the OoT recommended-settings prompt, GPU thread wake and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## 261106-v6

- Base: `nx2` `588bfa61` — upstream #314 first-run performance defaults,
  plus #224, #290 and #295.
- Ocarina of Time now asks on launch whether to use the recommended
  performance settings: FSR3 scaling, GPU accuracy Low, GPU NVDEC, async
  presentation and async shaders. They apply for the session and do not change
  saved preferences.
- New desktop configs receive those values as their first-run defaults.
- Keeps the GPU thread wake from Shakoquo's sharkiix work and the full
  superbuild fix set.
- Windows and Linux, standard and PGO.

## 261106-v4

- Base: `nx2` `a7a28175` — upstream PR #224 (async native discard), #290
  (worker lost-wake fix), #295 (misaligned SSBO accesses and compute write
  ordering).
- Added GPU thread wake from Shakoquo's sharkiix work: queued commands wake the
  GPU thread immediately; the poll interval is 500 µs instead of 1 ms.
- Keeps the full superbuild fix set: OoT reticle, GPU split, Bananza page-mark
  batching, Frizti ports, query timing, HMMA unroll, AMD-oriented fixes.
- Windows and Linux, standard and PGO.

## 261106-v3

- Base: `nx2` `c9bdbaa3` — upstream #290 and #295.
- Added PR #224 `EDEN_NX2_ASYNC_DISCARD=1`: native draws skip unbuilt pipelines
  instead of stalling; measured `draws held for unbuilt pipelines` dropped from
  816 ms to 0–8.7 ms per 10 s.
- Keeps the full superbuild fix set.
- Windows and Linux, standard and PGO.

## 261106-v2

- Base: `nx2` `e219d24c` — upstream #273 (AMD shader typing, atomic retries,
  compiler stalls) and #284 (MinGW AV1).
- First release with the full curated superbuild fix set: Bananza page-mark
  batching, OoT reticle, GPU split, Frizti ports, mja00 fixes, Nolar AMD fixes.
- Windows and Linux, standard and PGO.
- Includes reference builds from `e219d24c` and `55532f2d`.
