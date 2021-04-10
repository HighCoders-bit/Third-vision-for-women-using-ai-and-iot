# THIRD VISION FOR WOMEN USING AI AND IOT
## OVERVIEW
* In the following device we have implemented a voice recognition technique to turn on the device which then produces a non lethal shock to the atttacker in case the women faces trouble. 
* The GPS GSM technology implemented in the device is used to provide location status with Google map link to the relative and nearest police station.
Motion Sensor Camera is provided is implemented not only to detect criminal but also to prevent crime as the picture gets stored in SD card and also send   email to police department. 
* Vibration sensor is there to send the last location in case the device gets damaged. 
* Push Button (used for manual control)is used in case voice recognition module does not work ,the victim can activate the device by pressing the switch.
* Vibration motor  is used which vibrates for a window span of few seconds  in case the user turn on the device by mistake ,The user will get few seconds time to press terminal switch and thus prevent from creating un necessary chaos. 
* The terminal button which the user can press in case the device gets activated without proper intention. Terminal button will terminate the operation of the device immediately.
* AI  is implemented which provide us with crime prediction analysis. The following model is implemented with GUI app which allows only authorised person to access it and thus get detail information about  crime hotspot and live map location tracking. The police can compare victims location with the various crime predicted areas and thus efficiently track down the victim based on recent crime prone zones. Moreover, in this project we want to save the victim both by time and locality ensuring full safety.
## IOT 
* The motion sensor camera code is in----- sensing motions and click pictures.ino
* ALL the sensors integration with arduino mega to create a standalone device---Integration of sensors.ino
## AI
* ALL the algorithm implemented along with GUI app is-----SHAKSHAM APP.py
## USERMANUAL
* the dataset file(Westbengal crime(updated).xlsx)
* User registration.xlsx file contains the user id and password for the app
* Analysis based on AI model.text which contain detail analysis of WestBengal crime
## code snippets and output
### SAHELI DEVICE
/*FOR BOTH BUTTON AND VOICE*/
    if  (digitalRead(vib_pin) == 0 )
    {
     if (digitalRead(relay) == LOW ) 
     {
      Serial.println("Hello");
        lcd.clear();
       lcd.print("(NeedHelp)");
       delay(1000);
       lcd.clear();
       lcd.print("LATITUDE");
        lcd.print(gpslat, 6);
         lcd.setCursor(0,1);
         lcd.print("Longitude:");
         lcd.print(gpslon, 6);
         delay(10000);
         lcd.clear();
       
 <img src="https://user-images.githubusercontent.com/70643549/114269217-48274c80-9a23-11eb-870e-9a710704a90a.jpg" width="200" height="200"/>
 <img src="https://user-images.githubusercontent.com/70643549/114269218-4e1d2d80-9a23-11eb-90e4-ebd4ecf18bd8.jpg" width="200" height="200"/>


####  SENSING MOTION AND CLICKING PICTURES SEND TO GMAIL
  
  //esp_camera_fb_return(fb);
  Serial.printf("Image saved: %s\n", path.c_str());

  //send email
  Serial.println("Sending email...");
  //Set the Email host, port, account and password
  smtpData.setLogin("smtp.gmail.com", 587, emailSenderAccount, emailSenderPassword);
  
  //Set the sender name and Email
  smtpData.setSender("ESP32-CAM", emailSenderAccount);
  
  //Set Email priority or importance High, Normal, Low or 1 to 5 (1 is highest)
  smtpData.setPriority("Normal");

  //Set the subject
  smtpData.setSubject("Motion Detected - ESP32-CAM");
    
  //Set the message - normal text or html format
  smtpData.setMessage("<div style=\"color:#003366;font-size:20px;\">Image captured and attached.</div>", true);

  //Add recipients, can add more than one recipient
  smtpData.addRecipient(emailRecipient);
 
 
 
 
 <img src="https://user-images.githubusercontent.com/70643549/114269405-7fe2c400-9a24-11eb-9fff-486808370f86.jpg" width="200" height="200"/>
  
  
  ### SAKSHAM APP

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
          
          
<img src="https://user-images.githubusercontent.com/70643549/114269960-62fbc000-9a27-11eb-9b9a-d49f4145cc81.png" width="200" height="200"/>
<img src="https://user-images.githubusercontent.com/70643549/114270030-bec64900-9a27-11eb-87d5-cce10a003e41.png" width="200" height="200"/>
<img src="https://user-images.githubusercontent.com/70643549/114270051-db628100-9a27-11eb-8e8d-ba71ab31759f.png" width="200" height="200"/>
<img src="https://user-images.githubusercontent.com/70643549/114270092-27adc100-9a28-11eb-9078-7562445beeba.png"width="200" height="200"/>
