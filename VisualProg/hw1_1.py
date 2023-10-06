# 1
n = int(input("숫자를 입력하세요 "))

while n != 0 :
    result = int((n**2)**(1/2))
    print("=> ", result)

    n = int(input("숫자를 입력하세요"))

# 2
dong = ["흑석동","사당동","상도동","노량진동","규동"]
n = input("동을 입력하세요.")

while n != "종료" :
    if n in dong:
        print("%d번째 동입니다." % (dong.index(n)+1))
    else:
        dong.append(n)
        print("새로운 동명입니다. %d번째 동으로 등록합니다." % len(dong))

    n = input("동을 입력하세요.")

# 3
n = input("수?")
isPalNum = True

while n != "0":
    for i in range(int(len(n)/2)):
        if n[i] == n[-i-1]:
            pass
        else:
            isPalNum = False
            break

    if isPalNum == True:
        print("대칭수 입니다.")
    else:
        print("대칭수가 아닙니다.")

    n = input("수?")
    isPalNum = True

# 4
n = int(input("데이터를 입력하세요(입력을 마치려면 0을 입력하세요) \n"))
sortList = []

while n != 0:
    sortList.append(n)
    n = int(input())

sortList.sort()

for i in sortList:
    print(i, end =" ")

# 5
h = int(input("키(cm)는?"))
w = int(input("몸무게(kg)는?"))

bmi = w / (h*0.01)**2

if bmi < 20:
    state = "저체중"
elif 20 <= bmi < 25:
    state = "정상"
elif 25 <= bim < 30:
    state = "과체중"
else :
    state = "비만"

print("BMI는 {:.2f}로 {}입니다.".format(bmi,state))


# 6
w = int(input("원금을 입력하세요(원). "))
r = int(input("금리를 입력하세요(%). "))

print("원금 {}원 금리 {}% 입니다.".format(w,r))

print("기간 합계")
r = 1 + r*0.01
for i in range(1,21):
    w *= r
    print("{}년 {:.1f}".format(i,w))



# 7
import random
comWin = 0
myWin = 0
gameRound = 0

print("(라운드 %d)", gameRound)
print("컴퓨터가 결정했습니다.")
my = input("무엇을 내시겠습니까?(가위, 바위, 보)")

while comWin < 3 and myWin < 3:
    com = random.randint(1,3)


