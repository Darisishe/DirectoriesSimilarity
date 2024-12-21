# Add the source files in this directory
set(SOURCES 
      src/directories_comparator.cpp
      src/file/file.cpp
      src/similarity_entry/entry.cpp
      src/metric/LCS.cpp
      src/metric/levenshtein.cpp
      PUBLIC)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_sources(UnitTests PRIVATE ${SOURCES})