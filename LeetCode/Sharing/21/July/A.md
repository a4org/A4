# 群主的每日分享#1 
##### by Jiawei Wang 
##### July 27 2021

算上这两天（26 - 27）一共做了6道动态规划的题目<br>
其中26号一题 
* **[#121 Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)**
<br>

27号也就是今天一共做了5道题：
* **[#122 Best Time to Buy and Sell Stock ii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) **
* **[#123 Best TIme to Buy and Sell Stock iii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)**
* **[#188 Best Time to Buy and Sell Stock iv](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)**
* **[#309 Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)**
* **[#714 Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)**

就像之前的 `House Robber (i to iii)` 动态规划系列一样 总是做一个系列的题就罢了 总是做一个题的不同变种 就算是傻子也可以摸清其中的规律<br>
算下来 动态规划的题目 在Leetcode上也做了不下小十个了 现在回想起来当时想在leetcode上刷题 放弃了每天CodeForces的每天竞赛 还是因为这道当时完全傻眼的[Vacations](https://codeforces.com/problemset/problem/698/A) 当时看完视频解答之后才知道还有这样一种题型 （这道题的解答我写的非常详细 可以在[github](https://github.com/Angorithm4/Angorithm4/blob/main/CodeForces/Vacations.cpp)上找到） 于是才开始转向Leetcode专门练习这样的题目

做一个总结吧 做了这么多道同一个题的变种 还都是一个类型的解法 就叫做**DP基本型1**吧, 现在想到做过的大概有了五种吧，其余的等题目做多了再一起整理 像今天一样 

## Dynamic Programming Basic I
就以股票系列的经典题作为例题，刚做完的 **[#123 Best TIme to Buy and Sell Stock iii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)** 难度是Hard:

题目的大概意思是 给你一个价格的array 表示从第i到第n天这个股票的价格趋势 然后加一个限制条件 让你求怎样收益最大 这六道题都是这样<br>
这里的意思是你总共只能做两次交易 也就是买一次卖一次 然后买第二次卖第二次 问你最大收益是多少

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

所谓动态规划(Dynamic Programming) 就是为了解决一个问题 需要转化成很多个小问题 然后每个小问题要用到其他小问题的结果 所以说是动态的<br>
就像在这个问题中 为了求这个总利润的最大值 我们就转化成每一天的最大值 然后因为后一天的状态直接取决于前一天的各种状态 前一天是已经卖出去了股票 还是还持有，会直接影响到今天的选择。
<br>

上面我提到了一个关键字 -- **状态**, 在所有动态规划的题目中 最重要的就是写出状态转移方程 也就是各状态之间的联系。<br>

我先不多讲理论 直接进入这个例子 188题: <br>
根据题意 首先 对于每一天 只可能有四种状态:
* **刚买入第一支股票 但是还没有卖出 -- hold1**
* **刚卖出第一支股票 但是并未买入第二支 -- sold1**
* **刚买入第二支股票 但是还没有卖出 -- hold2**
* **刚卖出第二支股票 用光了所有的次数 -- sold2**

其他还有一种状态 也就是初始状态 一支股票都没买也没卖 这个状态就是0收益

这样就简单了 只要我们把每一天的各个状态给都考虑到 然后选取最大的利润 综合这些天 不就是总的最大利润吗？

**换句话说 你在某一天要做的事 只取决于在这一天前一天你做的事 你所需要做的 只是将这些状态之间的联系找出来**


对于任意的第i天 (i > 1)
* **刚买入第一支股票 但是还没有卖出 -- hold1**
```
hold1_i = max(0 - prices[i]), hold1_i-1)
```
这个式子表示 你现在要进入hold1这个状态 只取决于当前的price够不够小 <br>

* **刚卖出第一支股票 但是并未买入第二支 -- sold1**
```
sold1_i = max(hold1_i-1 + prices[i], sold1_i-1)
```
这个式子表示 你在这一天是否应该将股票卖出 进入 sold1 状态 完全取决于你卖掉该股票获得的总收益 `hold1_i-1 + prices[i]` (hold1_i-1 表示你在前一天买入该股票总收益) 相对于你前一天的 sold1 状态`sold1_i-1`是不是足够大 如果较大 就更新


* **刚买入第二支股票 但是还没有卖出 -- hold2**
```
hold2_i = max(sold1_i-1 - prices[i], hold2_i-1)
```
这个式子表示 你现在是否应该继续买入第二支股票 进入hold2状态 完全取决于你买入现在股票之后的总收益 `sold1_i-1 - prices[i]` 相对于你前一天的 hold2 状态 `hold2_i-1` 是否足够大 如果较大 就更新

* **刚卖出第二支股票 用光了所有的次数 -- sold2**
```
sold2_i = max(hold2_i-1 + prices[i], sold2_i-1)
```
这个式子表示 你现在是否应该卖出第二支股票 完成交易 进入 sold2 状态 完全取决于 你卖掉该股票获得的总收益 `hold2_i-1 + prices[i]` 相对你前一天的 hold2 状态 `hold2_i-1` 是否足够大 如果大 就更新



写完了状态转移方程 接下来需要做的 就是敲代码了 你只需要把每一天的这几种状态都表示出来 由于每一天的状态 完全取决于前一天的状态 所以每当你更新这一天的时候 你需要用四个临时变量来保存前一天的这四种状态<br>

```c
// #1 DP
int maxProfit(vector<int>& prices) {
int hold1 = INT_MIN, hold2 = INT_MIN;
int sold1 = 0, sold2 = 0;

for (auto p : prices) {
    int hold1_tmp = hold1; // hold1_i-1
    int hold2_tmp = hold2; // hold2_i-1
    int sold1_tmp = sold1; // sold1_i-1
    int sold2_tmp = sold2; // sold2_i-1

    hold1 = max(0-p, hold1_tmp);
    sold1 = max(hold1_tmp + p, sold1_tmp);
    hold2 = max(sold1_tmp - p, hold2_tmp);
    sold2 = max(hold2_tmp + p, sold2_tmp);
}

return max(sold1, sold2);
}
```

最后再取最大 就行 这个最大就表示你能获得的最大收益 因为你考虑到了每一种可能发生的情况  **:)**

****

### 后记
之后还会打卡更多DP的题目 如果一个类型做的多了 也会像今天这样归类为题型的 <br>

这几天忙着写OSDI的笔记 刚刚写完的第二章第四节的笔记[Chapter2/4. Inside a Hole Clock Tick](https://github.com/Angold-4/OSDI/blob/master/Chapter/Chapter2/4ClockTick.md) 讲述了在操作系统中一个时钟中断间隔 也就是16.67毫秒中发生的所有事 算是自己的得意之作了 接下来的两天争取把后面两篇笔记也写完 (名字都想好了) 然后完成第二章 **进程**<br>也算是对之前的一个月一个交代了吧 


