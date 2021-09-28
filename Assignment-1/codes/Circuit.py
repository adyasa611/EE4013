import numpy as np

B = np.array([[1,1,0,0],[0,-1,1,0],[0,0,-1,-1]])
Zb = np.array([[2,0,0,0],[0,5,0,0],[0,0,1,0],[0,0,0,10]])
vs =np.array([[10],[12],[0],[20]])
Bt = np.transpose(B)

a=np.matmul(B,np.matmul(Zb,Bt))
I=  np.matmul(np.linalg.inv(a),-1*np.matmul(B,vs))
print(I)