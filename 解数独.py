import numpy as np
row=np.zeros((9,9))
column=np.zeros((9,9))
place=np.zeros((9,9))
last=np.zeros((9,9))
def add_number(i,j,board):
    min=10
    p=0
    if(board[i][j]=='.'):
        for count in range(0,9):
            if((row[i][count].all()==0)and(column[j][count].all()==0)and(place[int(i/3)*3+int(j/3)][count].all()==0)):
                min=count   
                board[i][j]=str(count+1)
                row[i][count]=1
                column[j][count]=1
                place[int(i/3)*3+int(j/3)][count]=1
                return 1
        if(min==10):
            return 0
    else:
        p=int(board[i][j])-1
        row[i][p]=0
        column[j][p]=0
        place[int(i/3)*3+int(j/3)][p]=0
        for count in range(p+1,9):
            if((row[i][count].all()==0)and(column[j][count].all()==0)and(place[int(i/3)*3+int(j/3)][count].all()==0)):
                min=count   
                board[i][j]=str(count+1)
                row[i][count]=1
                column[j][count]=1
                place[int(i/3)*3+int(j/3)][count]=1
                return 1
        if(min==10):
            board[i][j]='.'
            return 0

def FindLast(i,j):
    for count1 in range(i,-1,-1):
        for count2 in range(j-1,-1,-1):
            if(last[count1][count2].all()==0):
                return count1,count2
        j=9

def solveSudoku(board):
    """
    :type board: List[List[str]]
    :rtype: None Do not return anything, modify board in-place instead.
    """
    i=0
    j=0
    for i in range(0,9):
        for j in range(0,9):
            if(board[i][j]!='.'):
                row[i][int(board[i][j])-1]=1
                column[j][int(board[i][j])-1]=1
                place[int(i/3)*3+int(j/3)][int(board[i][j])-1]=1
                last[i][j]=1
    i=0
    while(i<9):
        j=0
        while(j<9):
            if(last[i][j].all()==0):
                while(add_number(i,j,board)==0):
                    i,j=FindLast(i,j)
            j+=1
        i+=1

board=[[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]
solveSudoku(board)
print(board)
