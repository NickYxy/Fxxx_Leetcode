/*
 * @lc app=leetcode.cn id=2409 lang=cpp
 *
 * [2409] 统计共同度过的日子数
 */

// @lc code=start
class Solution {
public:
    int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int get(string& s) {
        int m, d;
        sscanf(s.c_str(), "%d-%d", &m, &d);
        int res;
        for (int i = 0; i < m; i ++ ) res += mon[i];
        return res + d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 = get(arriveAlice), a2 = get(leaveAlice);
        int b1 = get(arriveBob), b2 = get(leaveBob);

        return max(0, min(a2, b2) - max(a1, b1) + 1);
    }
};

//Go
func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
    months := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    convert := func (day string) int {
        m, _ := strconv.Atoi(day[:2])
        d, _ := strconv.Atoi(day[3:])

        total := 0
        for i := 0; i < m - 1; i++ {
            total += months[i];
        }
        total += d
        return total
    }

    a := convert(arriveAlice)
    a1 := convert(leaveAlice)
    b := convert(arriveBob)
    b1 := convert(leaveBob)
    if a1 < b || b1 < a {
        return 0
    }
    return min(a1, b1) - max(a, b) + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}

// @lc code=end

