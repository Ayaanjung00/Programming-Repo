import threading
count=0
def mainstory(count):
    count+=1
    if count==1 :
        print('��ī M�� �̳� �ڸ��߸��� ������ ����.\n������ ��Ӵ� ������� ģ�� H�� �� ���� ��Դ�.')
    elif count==2 :
        print('�Ӽ���')
    elif count==3 :
        print('�ٺ�')
    elif count== 4:
        print('������')

    timer=threading.Timer(1,july24,args=[count])
    timer.start()

    if count==5 :
        print('����')
        timer.cancel()

july24(0)

