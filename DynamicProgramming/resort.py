import sys

def solve(days, except_days):

    dp = [[sys.maxsize] * (2 * days + 1) for i in range(days + 1)]
    dp[0][0] = 0
    for i in range(days):
        for j in range(2 * i + 1):
            if dp[i][j] == sys.maxsize:
                continue
            if i + 1 in except_days:
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])
                continue
            # 하루 이용
            dp[i + 1][j] = min(dp[i][j] + 10000, dp[i + 1][j])
            # 3일권 이용
            for k in range(1, 4):
                if i + k > days:
                    break
                dp[i + k][j + 1] = min(dp[i][j] + 25000, dp[i + k][j + 1])
            # 5일권 이용
            for k in range(1, 6):
                if i + k > days:
                    break
                dp[i + k][j + 2] = min(dp[i][j] + 37000, dp[i + k][j + 2])
            if j >= 3:
                dp[i + 1][j - 3] = min(dp[i][j], dp[i + 1][j - 3])

    ans = sys.maxsize
    for i in range(len(dp[days])):
        ans = min(dp[days][i], ans)
    return ans

def main():
    days, n = map(int, input().split())
    if n == 0:
        print(solve(days, []))
        return
    except_days = map(int, input().split())
    print(solve(days, list(except_days)))
    return

main()
