# Automated Security Door

## Table of contents
* [General info](#general-info)
* [List of components](#list-of-components)
* [Working of the project](working-of-the-project)
* [Benefits of the project](benefits-of-the-project)

## General info

The project is built in order to fully automate the entry and exit (a common path) into a place. Only the person carrying valid ID card (i.e. RFID Tag) would be able pass.  The project obliviates the need of security guards too, so this reduces expenses as well as provides a reliable, human-error free system. In addition this, an e-mail will be sent to security head who can override the security from his/her smartphone through google assistant or blynk app over the internet.

## List of components

1.	NodeMCU esp8266
2.	RFID Reader
3.	RFID Tags
4.	IR Detector
5.	DC Motors
6.	Motor Driver IC
7.	Basic Electronics Components.

## Working of the project

The project,Security Door, works on NodeMCU (an arduino platform with built-in esp8266 module). RFIDs and Control over internet (i.e. IoT) are playing principal role in the project. Every authorized person would be having a RFID tag. While entering or exiting the place, each and every person has to scan his/her RFID tag in the RFID reader when he/she would be in front of IR scanner and reader will automatically reads the unique code stored within the RFID tag. Then that code will be matched, and on the basis validity, the person will be allowed to enter/exit to/from the place. In case of code does match or the person tries to move ,doors will be closed and won’t be opened until security head turn it off using Google Assistant or Blynk app.
This feature of project will save money required for security guards. Also, as it is a human free system, chances of errors will get reduced significantly. 

## Benefits of the project

•	Significantly reduces the need of security personnels.
•	Reduction in Error, as in human based security system, chances of human errors always be present.
•	Expenses will be plummeted tremendously because of no person will be there to check, so those expenditures will get obliviated, plus the whole will consume very low power as it is working on electronics devices.
