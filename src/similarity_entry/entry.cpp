#include <similarity_entry/entry.h>


SimilarityEntry::SimilarityEntry(const std::string& file1, const std::string& file2, double similarity)
  : file1_(file1), file2_(file2), similarity_(similarity) {
}

std::string SimilarityEntry::to_string() const {
  if (similarity_ == 100.0) {
    return file1_ + " - " + file2_;
  } else {
    return file1_ + " - " + file2_ + " - " + std::to_string(similarity_) + "%";
  }
}

double SimilarityEntry::getSimilarity() const {
  return similarity_;
}