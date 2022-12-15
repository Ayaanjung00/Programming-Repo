import threading
count=0
def mainstory(count):
    count+=1
    if count==1 :
        print('조카 M은 이날 코리야마로 여행을 갔다.\n집에는 어머니 요시코의 친구 H의 두 딸이 놀러왔다.')
    elif count==2 :
        print('임세은')
    elif count==3 :
        print('바보')
    elif count== 4:
        print('몬툐니')

    timer=threading.Timer(1,july24,args=[count])
    timer.start()

    if count==5 :
        print('종료')
        timer.cancel()

july24(0)

