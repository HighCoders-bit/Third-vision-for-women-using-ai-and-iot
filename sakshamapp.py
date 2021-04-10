import tkinter as tk 
from tkinter import ttk
from PIL import ImageTk,Image
from tkinter import simpledialog
import crimeprediction
import webbrowser

def GUI():
 win=tk.Tk()
 win.title('Crime prediction Analysis app')
 win.geometry('350x250')
 global panel,My_label

# label text for title 
 ttk.Label(win, text = "Smart crime analysis",  
          background = 'green', foreground ="white",  
          font = ("Times New Roman", 15)).pack()
  
# label 
 ttk.Label(win, text = "Select the choice :", 
          font = ("Times New Roman", 10)).pack()
 def dellabel():
    if mycombo.get()=='See graphs of prediction analysis':
        panel.pack_forget()
        My_label.pack_forget()
        mycombo.set(' ')
    if mycombo.get()=='see current year graph':
       label.pack_forget()
       My_label1.pack_forget()
       My_label2.pack_forget()
       My_label3.pack_forget()
       mycombo.set(' ')
    if mycombo.get()=='see statiscal results':
       Tex.pack_forget()
       mycombo.set(' ')
    if mycombo.get()=='Live map':
        if z==0:
           e.pack_forget()
           mycombo.set(' ')
        else:
           Btn1.pack_forget()
           mycombo.set(' ')
          
    if mycombo.get()=='see district':
       
       mycombo2.destroy()
       mycombo.set(' ')
    
    
        
  
               
 def comboclick(object):
    global panel,My_label,label,My_label1,My_label2,My_label3,Tex,Btn,g,Tex2,b3,b2,Btn1,e,z
   
    if    mycombo.get()=='See graphs of prediction analysis':
          img =Image.open("cluster.png")
          image1=img.resize((394,278))
          img3=ImageTk.PhotoImage(image1)
          panel=tk.Label(win, image =img3)
          panel.pack()
          my_image1=Image.open("orginal vs prediction.png")
          image2=my_image1.resize((400,400))
          image3=ImageTk.PhotoImage(image2)
          My_label=ttk.Label(win,image=image3)
          My_label.pack()
          win.mainloop()
       
           
    elif mycombo.get()=='see current year graph':
           img1=Image.open("harrasment.png")
           k=img1.resize((389,350))
           k1=ImageTk.PhotoImage(k)
           label=tk.Label(win,image=k1)
           label.pack(side='bottom')
           img2=Image.open("kidnapped.png")
           g=img2.resize((389,300))
           g1=ImageTk.PhotoImage(g)
           My_label1=tk.Label(win,image=g1)
           My_label1.pack(side='right')
           img3=Image.open("murder.png")
           s=img3.resize((389,370))
           s1=ImageTk.PhotoImage(s)
           My_label2=tk.Label(win,image=s1)
           My_label2.pack(side='left')
           img4=Image.open("rape.png")
           p=img4.resize((389,370))
           p1=ImageTk.PhotoImage(p)
           My_label3=tk.Label(win,image=p1)
           My_label3.pack()
           win.mainloop()
    elif  mycombo.get()== 'see statiscal results':
          
          
          f=open('Analysis (updated).txt',mode='r')
          scroll=tk.Scrollbar(win)
          scroll.pack(side='right',fill='y')
          Tex=tk.Text(win,height=100,width=200,yscrollcommand=scroll.set)
          scroll.config(command=Tex.yview)
          Tex.config(state='normal')
          Tex.insert(tk.INSERT,f.read())
          Tex.pack()
    elif  mycombo.get()== 'see district':
          global h, Tex1,mycombo2
          def combodistricts(object):
            for l in options:
                  if mycombo2.get()==l:
                      
                        h=crimeprediction.districts(l)
                        Tex1=tk.Text(win,height=20,width=100)
                        Tex1.config(state='normal')
                        Tex1.insert(tk.INSERT,h)
                        Tex1.pack()
                       
                        def deltest():
                           Tex1.pack_forget()
                           b2.pack_forget()
                         
                        b2 = tk.Button(win, text="Delete The text content", command=deltest)
                        b2.pack(side='bottom')
                   
                         
                    
                    
                   
                     
                     
                     
                   
          n=tk.StringVar()
          mycombo2=ttk.Combobox(win,width=15, textvariable=n)
          options= ('24 PARGANAS NORTH', '24 PARGANAS SOUTH', 'ASANSOL', 'BANKURA', 'BIRBHUM', 'BURDWAN ', 'COOCHBEHAR',
                                             'DAKSHIN DINAJPUR', 'DARJEELING', 'HOOGHLY', 'HOWRAH', 'HOWRAH CITY', 'HOWRAH G.R.P.', 
                                             'JALPAIGURI', 'KOLKATA', 'MALDA', 'PASCHIM MIDNAPUR', 'PURAB MIDNAPUR',
                                             'MURSHIDABAD', 'NADIA','PURULIA', 'SEALDAH G.R.P.', 'SILIGURI G.R.P.',
                                            'UTTAR DINAJPUR', 'BARRACKPORE')
        
          
          mycombo2['values']=options
          
        
          mycombo2.current()
          mycombo2.bind("<<ComboboxSelected>>",combodistricts)
        
          
          mycombo2.pack()
          
                    
          
         
          
          
         
    else:
          
           inp= simpledialog.askstring(title="LIVE MAP",prompt="Enter name of district(CAPITAL):")
           z=crimeprediction.maping(inp)
           if z==0:
               v=tk.StringVar()
               e=tk.Entry(win,textvariable=v)
               v.set("Please Check Spelling")
               e.pack()
           else:
             new1=1
             url1 = "file:///D:/NEW%20ML%20RESULTS/%20map.html"
             def openweb1():
                 webbrowser.open(url1,new=new1)
             Btn1 =tk.Button(win, text = "This opens Google FROM USER INPUT",command=openweb1)
             Btn1.pack()
         
           
         

   
   
 
 mycombo=ttk.Combobox(win,values=['See graphs of prediction analysis',
       'see current year graph',
       'see statiscal results',
       'Live map',
       'see district'],
        width=16,state='readonly')

 b1 = tk.Button(win, text="Delete content", command=dellabel)
 b1.pack(side='top')

 mycombo.current()          
 mycombo.bind("<<ComboboxSelected>>",comboclick)
 mycombo.pack()



 win.mainloop()
