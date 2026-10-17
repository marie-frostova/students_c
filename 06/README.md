Необходимо реализовать все `//TODO`, которые встречаются в `src_templates`.

Рекомендуемый порядок:

- `simple_list/simple_list.c`
- `list/list.c`
- `tasks/middle.c`
- `tasks/remove_nth_from_end.c`
- `tasks/remove_duplicates.c`
- `tasks/intersection.c`
- `tasks/merge.c`
- `tasks/cycle.c`
- `tasks/reverse.c`

Запускать так: находясь в папке 06 выполнить команду `make run`.

# Задачи

## Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/

Дан односвязный список. Разверните его и верните новую голову списка.

Пример
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
-> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
```

## Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Удалите из односвязного списка `n`-й узел с конца и верните голову изменённого списка. Гарантируется, что `n` допустимо.

Пример
```
1 -> 2 -> 3 -> 4 -> 5, n = 2
-> 1 -> 2 -> 3 -> 5
```

## Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/

Найдите и верните средний узел односвязного списка. Если узлов чётное количество, верните второй из двух средних.

Пример
```
1 -> 2 -> 3 -> 4 -> 5
-> 3
```

## Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/

Даны головы двух отсортированных по возрастанию односвязных списков. Объедините их в один отсортированный список и верните его голову.

Пример
```
1 -> 3 -> 5
2 -> 4 -> 6
-> 1 -> 2 -> 3 -> 4 -> 5 -> 6
```

## Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

Определите, содержит ли односвязный список цикл. Верните `true`, если при переходе по `next` можно снова попасть в уже посещённый узел, иначе верните `false`.

Примеры
```
1 -> 2 -> 3 -> 1 -> ... -> true
1 -> 2 -> 3 -> NULL  -> false
```

## Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/

Найдите узел, в котором пересекаются два односвязных списка, или верните `NULL`, если пересечения нет. Пересечение определяется по общему узлу, а не по совпадающим значениям.

Пример
```
A: 1 -> 2 \
           4 -> 5
B: 3 -----/
-> общий узел: 4
```

## Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Дан отсортированный по возрастанию односвязный список. Удалите повторяющиеся значения так, чтобы каждое значение осталось в списке только один раз.

Пример
```
1 -> 1 -> 2 -> 3 -> 3
-> 1 -> 2 -> 3
```