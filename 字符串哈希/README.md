### 字符串哈希

有很多字符串的问题可以用字符串哈希来做，不一定要用KMP算法。

这里的哈希方式是一些比较特殊的哈希方式，即**字符串前缀哈希**。比如有一个字符串`abcde`，则可以先预处理出来所有前缀的哈希，比如`h[1]`就表示`a`的哈希，`h[2]`就表示`ab`的哈希，特别的，定义`h[0]=0​`表示前0个字符的哈希值为`0`。

要定义某一个前缀的哈希值，只要把字符串看成是一个$P$进制的数，那么每一位的ASCII码就表示这一位的数字是多少。那么上面的例子的字符串哈希值（即对应的十进制的数值）为：
$$
a \times P^4 + b \times P^3 + c \times P^2 + d \times P^1 + e \times P^0
$$
转化成数字之后这个数字可能非常大，所以要取模一下，一般是对$2^{64}$取模，在C++里就只需要直接用`unsigned long long`来存储就行了，就不需要真正的写取模这个动作了。

需要注意：

1. 对字符串的每一位字符都不应该映射成`0​`，假如把一个字符`A`映射成`0`了，那么`AA`映射过来就也是`0`，就不对了。
2. 在哈希数字的时候可能会存在冲突，这个字符串哈希方法是不处理冲突的，经验上一般取$P=131$或者$P=13331$



使用这种方式，可以利用前缀哈希来求得每一个子串的哈希值，如果要求字符串下标从`L`到`R`的哈希值，只需要知道`1..L-1`的哈希值`h[L-1]`，`1..R`的哈希值`h[R]`。其实要计算的`L..R`的哈希值就是这段数的$P$进制表示，所以其实就是在$P$进制的意义上把`1..L-1`这个数左移到和`1..R`对齐，然后再用`1..R`的值给它减掉就行了。

因为取模运算对加减乘都是同态的，所以用取模后的结果来计算，再取模得到的结果也一定是正确的：
$$
Hash[L..R] = (Hash[R] - Hash[L-1] \times P^{R-L+1} + 2^{64}) \ \ mod \ \ 2^{64}
$$
因为直接用`unsigned long long`来存，所以这里的加模再取模也是没必要做的了。

