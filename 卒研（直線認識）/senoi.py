# -*- coding: utf-8 -*-
import picamera
import picamera.array
import cv2
import time
import RPi.GPIO as GPIO
import numpy as np
import math

left1=25#左前進
left2=24#左後退
right1=23#右前進
right2=22#右後退

GPIO.setmode(GPIO.BCM)

GPIO.setup(left1,GPIO.OUT)
GPIO.setup(left2,GPIO.OUT)
GPIO.setup(right1,GPIO.OUT)
GPIO.setup(right2,GPIO.OUT)

GPIO.setup(15,GPIO.OUT)
GPIO.setup(20,GPIO.OUT)

pwm_left1=GPIO.PWM(left1,100)
pwm_right1=GPIO.PWM(right1,100)
pwm_left2=GPIO.PWM(left2,100)
pwm_right2=GPIO.PWM(right2,100)
    
def front(subayasa):
    pwm_left2.start(0)
    pwm_right2.start(0)
    pwm_left1.start(subayasa)
    pwm_right1.start(subayasa)
    time.sleep(0.01)
        
def back():
    pwm_left1.start(0)
    pwm_right1.start(0)
    pwm_left2.start(60)
    pwm_right2.start(60)
    time.sleep(0.01)
    
def left(s1):
    pwm_left1.start(0)
    pwm_right2.start(0)
    pwm_left2.start(60)
    pwm_right1.start(60)
    time.sleep(s1)
               
def right(s2):
    pwm_left2.start(0)
    pwm_right1.start(0)
    pwm_left1.start(60)
    pwm_right2.start(60)
    time.sleep(s2)

def stop():
    pwm_left2.start(0)
    pwm_right1.start(0)
    pwm_left1.start(0)
    pwm_right2.start(0)
    time.sleep(0.01) 

subayasa=0
    
with picamera.PiCamera() as camera:
    with picamera.array.PiRGBArray(camera) as stream:
        camera.resolution = (320,240)

        while True:
            camera.capture(stream,'bgr',use_video_port=True)
            gray=cv2.cvtColor(stream.array,cv2.COLOR_BGR2GRAY)
            blur=cv2.Canny(gray,50,150,apertureSize=3)
            lines=cv2.HoughLinesP(blur,rho=1,theta=np.pi/180,threshold=100,minLineLength=170,maxLineGap=5)

            if GPIO.input(20)==GPIO.HIGH:
                time.sleep(0.5)
                subayasa=subayasa-10
                if subayasa<0:
                    subayasa=0
                    
            if GPIO.input(15)==GPIO.HIGH:
                time.sleep(0.5)
                subayasa=subayasa+10
                if subayasa>=70:
                    subayasa=70
                    
            front(subayasa)
            #print(subayasa)

            #rho,thetaはデフォルト
            #thresholdは直線と認定する最低限の値を設定。値を小さくすると直線として判定されたやすくなり、値を大きくすると直線として判定されにくくなる。
            #minLineLengthはみなす最低の長さを設定。値が大きいほど長い直線でないと認識されたい
            #maxLineGapは同一線上にある点の間隔の最大値を設定。値が大きいほど離れた点の直線を認識できる。
            
            if lines is not None:
                for x1,y1,x2,y2 in lines[0]:
                    
                    if x1>310 or x2>310 or x1<1 or x2<1:
                        break
                    cv2.line(stream.array,(x1,y1),(x2,y2),(0,0,255),2)

                    #hsvの値を取得
                    henkan1=y1-10 #取得座標の10ピクセル上
                    henkan2=y2-10
                    tyutenx=(x1+x2)/2
                    tyuteny=(henkan1+henkan2)/2
                    
                    startb,startg,startr=stream.array[henkan1][x1] #指定座標のbgrを取得
                    endb,endg,endr=stream.array[henkan2][x2]
                    centerb,centerg,centerr=stream.array[tyuteny][tyutenx]

                    b1=float(startb/255.0)
                    g1=float(startg/255.0)
                    r1=float(startr/255.0)

                    b2=float(endg/255.0)
                    g2=float(endg/255.0)
                    r2=float(endr/255.0)

                    b3=float(centerb/255.0)
                    g3=float(centerg/255.0)
                    r3=float(centerr/255.0)

                    r=float((r1+r2+r3)/3.0)
                    g=float((g1+g2+g3)/3.0)
                    b=float((b1+b2+b3)/3.0)

                    #print 'r=',r*255,'g=',g*255,'b=',b*255

                    mx,mn=max(r,g,b),min(r,g,b)

                    diff=mx-mn

                    #if mx==mn:
                        #h=0
                        
                    #if mx==r:
                        #h=60*float((g-b)/diff)
                        
                    #if mx==g:
                        #h=60*float((b-r)/diff)+120
                        
                    #if mx==b:
                        #h=60*float((r-g)/diff)+240
                        
                    #if h<0:
                        #h=h+360
                        
                    if mx!=0:
                        s=diff/mx
                        
                    if mx==0:
                        s=0
                        
                    v=mx

                    s=s*100
                    v=v*100

                    #print 's=',s,'v=',v

                    #線の傾き計算
                    y1=y1*-1
                    y2=y2*-1

                    y=float(y2-y1)
                    x=float(x2-x1)

                    #nagasa=math.sqrt(y*y+x*x)
                
                    if x==0 or y==0:
                        break
                    
                    z=float(y/x)
                    #z=round(z,1)
                    z=math.floor(z*10)/10
                    print '傾き',z
                    print '\n'
                    #print '長さ',nagasa

                    if z==0:
                        break

                    if z<0 and s<15 and v>=60:
                        if z==-0.1: z=1.1
                        elif z==-0.2: z=1.0
                        elif z==-0.3: z=0.9
                        elif z==-0.4: z=0.8
                        elif z==-0.5: z=0.7
                        elif z==-0.6: z=0.6
                        elif z==-0.7: z=0.5
                        elif z==-0.8: z=0.4
                        elif z==-0.9: z=0.3

                        else:
                            break
                                                            
                        left(z)
                        print '----'
                        print 'move'
                        break
                        
                    if z>=0 and s<15 and v>=60:
                        if z==0.1: z=1.3
                        elif z==0.2: z=1.25
                        elif z==0.3: z=1.2
                        elif z==0.4: z=1.15
                        elif z==0.5: z=1.1
                        elif z==0.6: z=1.05
                        elif z==0.7: z=1.0
                        elif z==0.8: z=0.95
                        elif z==0.9: z=0.9
                        
                        else:
                            break
                        
                        right(z)
                        break

            #cv2.imshow('stream',stream.array)

            if cv2.waitKey(1) & 0xFF ==ord('q'):
                break

            stream.seek(0)
            stream.truncate()

        GPIO.cleanup()
        cv2.destroyAllWindows()

        
