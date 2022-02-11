# Client-Server-App
Client-server app on Qt with C++
## Description
This is a client-server app. The server is waiting for a connection and an incoming file from the client. A user can choose a picture from a local directory with the button “Choose a file” in a client GUI. After receiving the picture, the server sends a signal to GUI to show it. Type of the file is limited: only “.png” files will be shown.
The client can send one picture after another and the server will show them successively.

## About the project
### Client side
The client has a GUI with a button for the user to choose a picture. After the picture is chosen, the client converts the picture to the QBytesArray, connects to the server and sends the converted file to the server.

### Server side
The server listens to a localhost. After a connection is established and the picture is received, the server sends a signal and picture, converted to QBytesArray, to the GUI to show this picture. 
This picture is shown in the label. The picture is resized to fit the label.

## Example
Here are examples of how the program works

<img src="https://github.com/katerinavlasova/Client-Server-App/blob/master/media/start_program.png" width="550" height= "250">
Click button "Choose a file"
<img src="https://github.com/katerinavlasova/Client-Server-App/blob/master/media/choose_first_file.png" width="550" height= "250">
After the file is chosen
<img src="https://github.com/katerinavlasova/Client-Server-App/blob/master/media/show_first_file.png" width="550" height= "250">
After another file is chosen
<img src="https://github.com/katerinavlasova/Client-Server-App/blob/master/media/show_second_file.png" width="550" height= "250">


