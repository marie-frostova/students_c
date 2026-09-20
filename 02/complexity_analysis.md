1
```
int fun(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) 
	        max = arr[i];
    }
    return max;
}
```

2
```
int fun(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) 
	    sum += arr[i];
    for (int i = 0; i < n; i++) 
	    arr[i] = sum - arr[i];
    return sum;
}
```

3
```
int fun(int n) {
    int count = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                count++;
    return count;
}
```

4
```
int fun(int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            count++;
    return count;
}
```

5
```
int fun(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            count++;
    return count;
}
```

6
```
int fun(int n) {
    int count = 0;
    while (n > 1) {
        n = n / 2;
        count++;
    }
    return count;
}
```

7
```
int fun(int n) {
    int count = 0;
    for (int i = 1; i < n; i *= 2) {
        count++;
    }
    return count;
}
```

8
```
int fun(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        count++;
    }
    return count;
}
```

9
```
int fun(int n) {
    int count = 0;
    for (int i = 1; i < n; i *= 2)
        for (int j = 0; j < n; j += i)
            count++;
    return count;
}
```

10
```
int fun(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j += i)
            count++;
    return count;
}
```

11
```
long fun(int n) {
    if (n <= 1) 
	    return n;
    return fun(n - 1) + fun(n - 2);
}
```

12
```
void fun(int arr[], int start, int n) {
    if (start == n) {
        print_array(arr, n);
        return;
    }
    for (int i = start; i < n; i++) {
        swap(&arr[start], &arr[i]);
        fun(arr, start + 1, n);
        swap(&arr[start], &arr[i]);
    }
}
```

13
```
int check(int i) {
    return rand() % 2;
}

void fun(int arr[], int n) {
    for (int i = 0; i < n && check(i); i++) {
	    arr[i] = i;
    }
    print_array(arr, n);
}
```