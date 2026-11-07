# Changelog

All releases are unofficial builds. See the GitHub releases for assets and
checksums.

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
