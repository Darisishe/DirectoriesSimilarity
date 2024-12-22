# Библиотека для определения похожести директорий
Код обходит файлы в директории, сравнивая содержимое файлов и определяет "похожесть" файлов, согласно выбранной метрике
# Компиляция
таргет для сборки основной программы - DirectorySimilarity
таргет для сборки юнит-тестов - UnitTests:

# Структура проекта
Для юнит-тестирования использовался googletest.

src/metric - предоставлен интерфейс для переопределения метрики между строками (реализовано расстояние Левенштейна, поиск наибольшей общей подстроки с помощью хэшей за $O(n\log^2(n))$, простая метрика на основе количества символов (использует подсчет на GPU через CUDA))

src/file - вспомогательный класс для хранения имени+содержания файла

src/similarity_entry - вспомогательный класс для хранения пар файлов и их похожести

include/directories_comparator - сам компаратор директорий. Обходит директории первой папки параллельно с помощью `tbb::parallel_for`

Использование компаратора:
1) Выбрать метрику
2) `DirectoriesComparator<Metric> comparator(dir1, dir2, percentage);`
3) `comparator.calculateSimilarities()` - результат работы
