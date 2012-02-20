limit=int(raw_input());
a=[0] * 12
s = raw_input();
s = s.split(' ')
a = map(int, s)
a.sort()
a.reverse()
ans = 0
while limit>0 and ans < 12:
  limit-=a[ans];
  ans += 1;
if ans == 12 and limit > 0:
	print -1
else:
	print ans
