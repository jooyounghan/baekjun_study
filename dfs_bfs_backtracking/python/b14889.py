N = int(input())
team_stat = [list(map(int, input().split())) for _ in range(N)]
min_num = 100000
team = [0] * N

def get_status(team_in):
    status = 0
    for p1 in team_in:
        for p2 in team_in:
            status += team_stat[p1][p2]
    return status

def backtracking(team, pos, cnt):
    global min_num
    if cnt == N / 2:
        team1 = []
        team2 = []
        for i in range(N):
            if team[i]:
                team1.append(i)
            else:
                team2.append(i)
        team1_status = get_status(team1)
        team2_status = get_status(team2)
        result = team1_status - team2_status if team1_status > team2_status else team2_status - team1_status
        if result < min_num:
            min_num = result
        return
    
    if N / 2 < pos - cnt:
        return

    team[pos] = 1
    backtracking(team, pos + 1, cnt + 1)
    team[pos] = 0
    backtracking(team, pos + 1, cnt)

backtracking(team, 0, 0)
print(min_num)