n = int(raw_input())
data = map(int, raw_input().split())
count = (5010)*[0]
ret = int(0)
for i in range(n):
	if data[i] > n or data[i] < 1 or count[data[i]] >= 1:
		ret+=1
	count[data[i]]+=1
print ret
