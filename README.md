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
         ![IMG_20200616_160037](https://user-images.githubusercontent.com/70643549/114269217-48274c80-9a23-11eb-870e-9a710704a90a.jpg)
!!![IMG_20200616_160144](https://user-images.githubusercontent.com/70643549/114269218-4e1d2d80-9a23-11eb-90e4-ebd4ecf18bd8.jpg)
#### SENSING MOTION AND CLICKING PICTURES SEND TO GMAIL
  
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
  
  ![IMG246](https://user-images.githubusercontent.com/70643549/114269405-7fe2c400-9a24-11eb-9fff-486808370f86.jpg)
  ### SAKSHAM APP

  



