# Changelog

All releases are unofficial builds. See the GitHub releases for assets and
checksums.

## Unreleased

- Ocarina of Time now asks once per launch whether to use the recommended
  performance settings: FSR3 scaling, GPU accuracy Low, GPU NVDEC, async
  presentation and async shaders. The settings apply for the session and do
  not change saved preferences.
- New desktop configs still receive those values as their first-run defaults.

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
