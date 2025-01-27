### 01背包

特点：有$N$种物品和一个容量是$V$的背包，每个物品有体积$v_i$和价值权重$w_i$，每种物品只能用一次（01背包的由来），求能放到背包里，使得价值权重之和最大是多少。

基于第$i$件物品选和不选两种情况，可以得到它的状态转移：
$$
f[i,j] = Max(f[i-1, j], f[i-1, j - v[i]] + w[i]), \ \ \ v[i] <= j
$$

#### 一维化

因为第$i$层只和自己以及第$i-1$层有关系，所以可以把这个维度去掉，但是注意到$f[i-1, j - v[i]] + w[i]$一定用的是第$i-1$层的而不是第$i$层的，所以对于体积$j$要反向遍历，防止把它变成了第$i$层的，这样算就不对了。

### 完全背包

特点：每种物品可以用无限次。

基于第$i$件物品选$k$个的情况，可以得到它的状态转移：
$$
f[i,j] = Max(f[i-1, j-v[i]*k] + w[i]*k), \ \ \ k * v[i] <= j
$$

#### 公式优化

由状态转移知：
$$
\begin{align}
f[i,j]&=Max(f[i-1,j], &f[i-1,j-v]&+w, & f[i-1,j-2v]&+2w, & f[i-1,j-3v]&+3w,...) \\
f[i,j-v]&=Max( &f[i-1,j-v]&, & f[i-1,j-2v]&+w, & f[i-1,j-3v]&+2w, ...)
\end{align}
$$
从而上式子的后面部分就是$f[i,j-v]+w$，所以优化后$f[i,j] = Max(f[i-1,j], f[i,j-v]+w)$。

#### 一维化

完全背包也可以优化成一维的，在公式优化的基础上直接删掉第一维就行了。因为转移时候是从第$i$维到第$i$维的，所以不需要把对体积（第二维）的遍历反向。

> 对于一维化后的代码，01背包是从大到小遍历体积，完全背包是从小到大遍历体积，别的地方完全没区别。

### 多重背包

特点：每种物品只有$s_i$个，即不同种物品有自己的个数限制。

基于第$i$件物品选$k$个的情况，可以得到它的状态转移：
$$
f[i,j] = Max(f[i-1, j-v[i]*k] + w[i]*k), \ \ \ k * v[i] <= j \ \ \wedge \ \ k <= s[i]
$$
其中$f[i,j]$表示从前$i$种物品里，最多选$s[i]$个，背包体积是$v[j]$，能选出的最大价值权重。

这个朴素的状态转移方程和完全背包的很像，只不过第$i$个物品可以选的数量又多了一个限制，即不超过$s_i$个。

#### 多重背包不能直接用完全背包的优化方法

由状态转移知：
$$
\begin{align}
f[i,j]&=Max(f[i-1,j], &f[i-1,j-v]&+w, & f[i-1,j-2v]&+2w, & f[i-1,j-3v]+3w & , &..., \ \ \ & f[i-1,j-sv]+sw &) \\
f[i,j-v]&=Max( &f[i-1,j-v]&, & f[i-1,j-2v]&+w, & f[i-1,j-3v]+2w & , &..., \ \ \ & f[i-1,j-sv]+(s-1)w & , f[i-1,j-(s+1)v]+sw)
\end{align}
$$
多出了一项$f[i-1,j-(s+1)v]+sw$，从带上这项的$Max$没法求得前面$s$项的$Max$，所以就不能直接用完全背包的优化方法。

#### 二进制优化

比如某个$s[i]=1023$，从$0$枚举到$1023$是很低效的，可以用二进制的方式，将若干个物品打包在一起考虑：
$$
1,2,4,8,...,512
$$
如此打包成$10$组，每组只能选$0$或者$1$次，这样也能拼出所有的可能，把一组的物品看成一个物品，就转化了01背包问题。

上面是一个$s[i]$恰好等于$2^k-1$的例子，对于更一般的例子，只要让最后一个打包和前面的所有打包加起来正好等于$s[i]$，那么用这些数就能凑出$0$到$s[i]$之间的所有数了。例如$s[i]=200$，那么数是：
$$
1,2,4,8,16,32,64,73
$$
即最后一个打包数$73$和前面所有打包数的加起来正好等于$s[i]=200$就行了。

这样就能把每个$s[i]$个相同的物品**打包**成$log(s[i])$个打包物品，然后用01背包问题求解。优化前的时间复杂度是$O(N \cdot V \cdot S)$，优化后的时间复杂度是$O(N \cdot V \cdot log(S))$。

> 因为$N$个物品里每个能取$s[i]$个的物品都能打包成$log(s[i])$个物品，所以最后打包完的新物品总数是$N\cdot log(S)$规模的，解题之前要先算一下这个数，才知道存新物品的数组开多大。

#### 一维化

因为打包完之后就变成了01背包问题，所以一维化就是01背包问题的一维化。多重背包问题的难点在物品打包上，不在一维化上。

### 分组背包

特点：物品有若干组，每一组里有若干个，每个组里最多只能选一种物品（组内物品互斥）。

状态表示：

- 集合：$f[i,j]$表示只从前$i$组物品里选，且总体积不大于$j$的所有选法。

- 属性：$f[i,j]$的值表示这个集合里所有选法的价值权重的最大值。

状态计算：

基于第$i$组物品一个都不选以及选第几个（因为只能选其中一个）的情况，可以得到它的状态转移：
$$
f[i,j] = Max(f[i-1,j], f[i-1, j-v[i,k]] + w[i,k])
$$
其中$[i,k]$表示第$i$组中的第$k$个物品。

#### 一维化

分组背包也是可以一维化，和前面一样，如果转移时候用的是上一层的状态，那么就从大到小遍历体积；如果用的是本层的状态，那么就从小到大遍历体积。
$$
f[j] = Max(f[j], f[j-v[i,k]] + w[i,k])
$$
