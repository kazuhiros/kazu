from sklearn import datasets
import numpy as np
from sklearn.ensemble import RandomForestClassifier#ランダムフォレスト分類器のインポート
import cv2
import glob
from itertools import chain
from matplotlib import pyplot as plt

#宣言と初期化
n=0#ループカウンタ変数
humantest=[]
cattest=[]
dogtest=[]
# 以下の４行は，06-1.py 用にサンプルデータを読み込んでいる．06-2.py では，人，猫，犬の顔画像を読み込むこと．

#cv06testに入っている画像のパスをfile1へ順番に入力していく
file1=sorted(glob.glob('cv06test/*.jpg'))
#print(file1)
for img in file1:
    n+=1
    if(n<=10):#人間のテスト画像取り込み
        humantest.append(cv2.imread(img,0))
        #plt.imshow(humantest)
        #plt.show()
    elif(10<n<=20):#猫のテスト画像取り込み
        cattest.append(cv2.imread(img,0))
        #plt.imshow(cattest)
        #plt.show()
    elif(20<n<=30):#犬のテスト画像取り込み
        dogtest.append(cv2.imread(img,0))
        #plt.imshow(dogtest)
        #plt.show() 
    else:
        break

#testデータの特徴量抽出
test=np.array(humantest+cattest+dogtest)
testvector=test.reshape(test.shape[0],-1)
print("testvector")
print(testvector,"\n")

#testデータのラベル作り
human_test_label=[0 for i in range(10)]
cat_test_label=[1 for i in range(10)]
dog_test_label=[2 for i in range(10)]
testlabel = np.array(human_test_label+cat_test_label+dog_test_label)

#宣言と初期化
n=0
humantrain=[]
cattrain=[]
dogtrain=[]
#cv06trainningに入っている画像のパスをfile2へ順番に入れていく
file2=sorted(glob.glob('cv06trainning/*.jpg'))
for img in file2:
    n+=1
    if(n<=30):#人間のトレーニング画像取り込み
        humantrain.append(cv2.imread(img,0))
        #plt.imshow(humantrain)
         #plt.show()
    elif(30<n<=60):#猫のトレーニング画像取り込み
        cattrain.append(cv2.imread(img,0))
        #plt.imshow(cattrain)
        #plt.show()
    elif(60<n<=90):#犬のトレーニング画像取り込み
        dogtrain.append(cv2.imread(img,0))
        #plt.imshow(dogtrain)
        #plt.show() 
    else:
        break
        
#trainデータの特徴量抽出
train=np.array(humantrain+cattrain+dogtrain)
trainvector=train.reshape(train.shape[0],-1)
print("trainvector")
print(trainvector,"\n")

#trainデータのラベル作り
human_train_label=[0 for i in range(30)]
cat_train_label=[1 for i in range(30)]
dog_train_label=[2 for i in range(30)]
trainlabel = np.array(human_train_label+cat_train_label+dog_train_label)
          
# 06-1.py では，ここに SVM を設定する関数を挿入せよ．06-2.py では，ここに Random Forest を設定する関数を挿入せよ．モデルの変数名は model とせよ．
# 06-1.py では，ここに SVM を学習する関数を挿入せよ．06-2.py では，ここに Random Forest を学習する関数を挿入せよ．
model = RandomForestClassifier()

# 06-2.py で多次元特徴量である画像を読み込んだ場合，そのままでは使用不可能．06-2.py では可視化は不要．そのかわり，識別性能を識別成功率として示すこと．
model.fit(trainvector,trainlabel)
predictions = model.predict(testvector)
print("予測したデータのラベル")
print(predictions)
print("テストデータ（正解）のラベル")
print(testlabel)
print("※今回　0;人　1;猫　2;犬　のようにラベルを割り振った\n")

#識別数の計算
count=0
for i in range(30):
    if(predictions[i]==testlabel[i]):
        count+=1
        
#結果の表示    
print("識別成功数=",count)
print("識別成功率=%f"%(count/30*100))


# In[ ]:




