### 求组合数

组合数$C_a^b$有很多求法，根据范围和场景不同选取不同的求法。

注：以下标注的时间复杂度中，用$N$表示$a$和$b$的规模，用$P$表示模数$p$的规模。

#### 递推打表（10万组查询，$1\leq b \leq a \leq 2000$）

如果$a$和$b$的范围不大，但是查询次数很多，可以把所有的$C_a^b$打成表，然后每次查表就行了，可以根据递推式：
$$
C_a^b = C_{a-1}^b + C_{a-1}^{b-1}
$$
两重循环来求得。这个式子可以简单证明，$a$个元素里取$b$个，可以先挑一个元素，如果不取这个元素，那就是$C_{a-1}^b$，如果取了这个元素，那么只要再取$b-1$个元素，也就是$C_{a-1}^{b-1}$，两个加起来就是$C_a^b$得所有情况了，不重不漏。

边界：$C_a^0 = 1$。

> 时间复杂度$O(N^2)$

#### 预处理打表（10万组查询，$1\leq b \leq a \leq 10^5$）

因为$C_a^b$还可以这样求：
$$
C_a^b = \frac{a!}{(b-a)!b!}
$$
可以预处理出每个数的阶乘表：
$$
fact[i] = i! \ mod \ 1e9+7
$$
但是两个数先取模再做除法，和先做除法再取模是不相等的：
$$
\frac{M \ mod \ p}{N \ mod \ p} \neq \frac{M}{N} \ mod \ p
$$
所以可以把每个数阶乘对题目给定的模的乘法逆元也求出来打表：
$$
infact[i] = (i!)^{-1} \ mod \ 1e9 + 7
$$
除法就相当于乘逆元，也就是说：
$$
\frac{M \ mod \ p}{N \ mod \ p} = M \cdot N^{-1}
$$
其中$N^{-1}$是$N$模$p$时候的乘法逆元。

由此，知：
$$
\begin{align}
C_a^b &= \frac{a!}{(b-a)!b!} \\
&= fact[a] \cdot infact[b-a] \cdot infact[b]
\end{align}
$$
这样就能用预处理的结果在$O(1)$的时间里把每个查询的组合数求出来了。一般给出的模是$1e9+7$，是一个质数，所以对这个模的逆元可以用**费马小定理+快速幂**来求。

递归出口$fact[0]=infact[0]=1$，即$0$的阶乘一定是$1$，这个数的逆元也是$1$。

阶乘和阶乘逆元都是递推的过程：
$$
\begin{align}
fact[i] &= fact[i-1] * i \\
infact[i] &= infact[i-1] * i的逆元
\end{align}
$$
 这里是因为对同一个模的逆元是满足乘法结合律的，即
$$
M的逆元 \times N的逆元 = (M \times N)的逆元
$$
所以上面$(i-1)!$的逆元乘以$i$的逆元，就是$i$的阶乘的逆元，就是$infact[i]$了。

> 时间复杂度$N \cdot logN$

#### 卢卡斯定理（20组查询，$1 \leq b \leq a \leq 10^{18}$，$1 \leq p \leq 10^5$）

卢卡斯定理描述了$C_a^b$在模$p$的情况下的一个同余式子：
$$
C_a^b \equiv C_{a \ mod \ p}^{b \ mod \ p} \cdot C_{a / p}^{b / p} \ \ \ (mod \ p)
$$


> 时间复杂度$log_pN \cdot p \cdot logp$

因为$log_pN$和$logp$不可能同时取到极值，只会一个大一个小，所以实际的速度比这个看起来的规模快一些。

#### 高精度组合数

有的时候，要求的$C_a^b$很大，并且不能模一个数让它变小，所以要用高精度把组合数算出来。

可以直接根据定义：
$$
C_a^b = \frac{a \times (a-1) \times ... \times (a-b+1)}{b \times (b-1) \times ... \times 1}
$$
这样要实现一个高精度乘法，一个高精度除法，比较麻烦。

可以先将$C_a^b$在下面这个定义式上分解质因数：
$$
\begin{align}
C_a^b &= \frac{a!}{b!(a-b)!} \\
&= p_1^{\alpha_1} \times p_2^{\alpha_2} \times p_k^{\alpha_k}
\end{align}
$$
这样就只要再实现一个高精度乘法就行了。

至于如何求阶乘里包含多少个因子$p$，可以用这样的方法：
$$
a!中包含因子p的数量 = \lfloor \frac{a}{p} \rfloor + \lfloor \frac{a}{p^2} \rfloor + \lfloor \frac{a}{p^3} \rfloor + ...
$$
也就是把$a!$里$p$的倍数、$p^2$的倍数、$p^3$的倍数...全统计了一遍，最后加起来就是$a!$中包含因子$p$的数量。

1. 筛质数，题目要求$C_a^b$，那就把$1$~$a$内的质数都算出来打表
2. 求阶乘里每个质数出现的次数，用上面的公式$\frac{a!}{b!(a-b)!}$，分母里分解出来的就加上，分子里分解出来的就减掉，最后得到的就是$C_a^b$分解质因数的结果$p_1^{\alpha_1} \times p_2^{\alpha_2} \times p_k^{\alpha_k}$
3. 实现高精度乘法，把结果算出来