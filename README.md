# 1C_Contest
Конев Сергей Александрович, Задача №4
# Компиляция
таргет для сборки основной программы - main
таргет для сборки юнит-тестов - unit_tests_run:
1) mkdir build_tests
2) cd build_tests
3) cmake ..
4) cmake --build . --target unit_tests_run
5) запустить unit_tests_run
6) 
(иначе ломаются относительные пути к тестовым директориям в юнит-тестах)
# Структура проекта
Для юнит-тестирования использовался googletest.

src/distance - предоставлен интерфейс для переопределения метрики между строками (реализовано расстояние Левенштейна, поиск наибольшей общей подстроки с помощью хэшей за $O(n\log^2(n))$

src/file - вспомогательный класс для хранения имени+содержания файла

src/similarity_entry - вспомогательный класс для хранения пар файлов и их похожести

src/directories_comparator - сам компаратор директорий

Использование компаратора:
1) Определить метрику (LevenshteinDistance metric)
2) DirectoriesComparator comparator(dir1, dir2, percentage, metric);
3) comparator.calculateSimilarities() - результат работы
