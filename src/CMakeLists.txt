# Add the source files in this directory
set(SOURCES
      src/file/file.cpp
      src/similarity_entry/entry.cpp
      src/metric/LCS.cpp
      src/metric/levenshtein.cpp
      src/metric/counting.cpp
      src/metric/count.cu
      PUBLIC)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_sources(UnitTests PRIVATE ${SOURCES})