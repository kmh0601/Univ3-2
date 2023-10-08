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
# 7
import random
comWin = 0
myWin = 0
gameRound = 1
SRP = {1:"가위", 2:"바위",3:"보"}
print("가위바위보 게임")

while comWin < 3 and myWin < 3:
    print("(라운드 {})" .format(gameRound))
    while True:
        print("컴퓨터가 결정했습니다.")
        com = SRP[random.randint(1,3)]
        my = input("무엇을 내시겠습니까?(가위, 바위, 보)")

        if my == "가위":
            if com == "가위":
                #비김
                print("비겼습니다. 다시 입력하세요")
            elif com == "바위":
                #컴 이김
                print("컴퓨터는 {}, 당신은 {}, 컴퓨터가 이겼습니다.".format(com, my))
                comWin += 1
                break
            elif com == "보":
                #컴 짐
                print("컴퓨터는 {}, 당신은 {}, 당신이 이겼습니다.".format(com,my))
                myWin += 1
                break

        elif my == "바위":
            if com == "바위":
                #비김
                print("비겼습니다. 다시 입력하세요")
            elif com == "보":
                #컴 이김
                print("컴퓨터는 {}, 당신은 {}, 컴퓨터가 이겼습니다.".format(com, my))
                comWin += 1
                break
            elif com == "가위":
                #컴 짐
                print("컴퓨터는 {}, 당신은 {}, 당신이 이겼습니다.".format(com,my))
                myWin += 1
                break

        elif my == "보":
            if com == "보":
                #비김
                print("비겼습니다. 다시 입력하세요")
            elif com == "가위":
                #컴 이김
                print("컴퓨터는 {}, 당신은 {}, 컴퓨터가 이겼습니다.".format(com, my))
                comWin += 1
                break
            elif com == "바위":
                #컴 짐
                print("컴퓨터는 {}, 당신은 {}, 당신이 이겼습니다.".format(com,my))
                myWin += 1
                break
        else:
            print("잘못 입력했습니다. 다시 입력하세요")

    print("성적 : {}승 {}패".format(myWin,comWin))
    gameRound += 1

if comWin > myWin:
    print("컴퓨터가 최종으로 이겼습니다!")
else:
    print("당신이 최종으로 이겼습니다!")


#8
n = int(input("N?"))
m = int(input("M?(M-N이 0이상 3이하 이어야 합니다.)"))
for i in range(1,10):
    for j in range(n,m+1):
        print("{}x{}={}".format(j,i,i*j),end="\t\t")
    print()

# 9
# 입력받은 문자를 두 칸 뒤의 알파벳으로 교체
target = list(input("문장 : "))
for i in range(len(target)):
    if target[i] != " ":
        target[i] = chr(ord(target[i])+2)
print("암호화된 문장 :","".join(target))

# 10
import random
import math

mfSize = 15
distance = math.inf
mfX = random.randint(20,80)
mfY = random.randint(20,80)

print("자기장 생성기를 찾으세요(크기{})".format(mfSize))
while mfSize > 0:
    myX, myY = map(int,input("좌표는?").split())
    tempDistance = math.sqrt((mfX-myX)**2 + (mfY-myY)**2)

    if(tempDistance <= 1.5):
        print("({},{})은 자기장 안입니다. 자기장 생성기를 찾았습니다.(거리 {:.1f})".format(myX,myY,tempDistance))
        print("자기장 생성기의 좌표는({},{})입니다. 오늘은 치킨이닭!".format(mfX,mfY))
        break
    elif(tempDistance <= mfSize):
        print("({},{})은 자기장 안입니다.".format(myX,myY),end=" ")
    else:
        print("({},{})은 자기장 밖입니다.".format(myX,myY),end=" ")

    if(tempDistance > distance):
        distance = tempDistance
        print("자기장 생성기에서 멀어졌습니다.(크기{})".format(mfSize))
    elif(tempDistance < distance):
        distance = tempDistance
        print("자기장 생성기에 가까워졌습니다.(크기{})".format(mfSize))
    else:
        distance = tempDistance
        print("자기장 생성기에서 같은 거리입니다.(크기{})".format(mfSize))

    mfSize -= 0.5

if mfSize <= 0:
    print("자기장 생성기를 찾지못했습니다. 자기장 생성기의 좌표는 ({},{})입니다. 오늘은 굶어야 합니다 ㅠㅠ".format(mfX, mfY))



# 11
menuDict = {"국수":6000,"비빔밥":8000,"햄버거":4500,"국밥":7500,"스파게티":11000,"피자":9900}
count = 0
menu = input("메뉴? (끝내려면 '종료') ")
while menu != "종료":
    if menu in menuDict:
        count += menuDict[menu]
    else:
        print("그런 메뉴는 없습니다.")
    menu = input("메뉴? (끝내려면 '종료') ")
print("총액 {}원 입니다.".format(count))