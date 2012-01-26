import os
import shutil
tcdir = '/Users/M/Documents/Xcode Projects/Topcoder'
targetdir = '/Users/M/Desktop/Algorithm/Topcoder'
dirlist = os.listdir(tcdir)
for i in dirlist:
	if i[0]=='.' or os.path.isdir(tcdir + '/'+ i)!=True:
		continue
	a = i.split('-')
	if a[1] == 'Round1':
		a[1] = 'div2'
	targetname = a[0]+'-'+a[1]+'-'+a[2] + '.cpp'
	tmppath = tcdir+'/'+i
	tmplist = os.listdir(tmppath)
	if tmplist.count('main.cpp') == 1:
		shutil.copy(tmppath+'/main.cpp', targetdir+'/'+targetname)
	else:
		for j in tmplist:
			if os.path.isdir(tmppath+'/'+j):
				shutil.copy(tmppath+'/'+j+'/main.cpp', targetdir+'/'+targetname)
				break