vtk_add_test_cxx(
  TemporalStatistics.cxx
  TestBSplineTransform.cxx
  TestPolyDataSilhouette.cxx
  TestProcrustesAlignmentFilter.cxx,NO_VALID
  TestTemporalCacheSimple.cxx,NO_VALID
  TestTemporalCacheTemporal.cxx,NO_VALID
  TestTemporalFractal.cxx
  )
vtk_test_cxx_executable(${vtk-module}CxxTests RENDERING_FACTORY)
