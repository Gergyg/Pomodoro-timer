from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
import os

gauth = GoogleAuth()
drive = GoogleDrive(gauth)

def upload_dir(dir_path, file_id):
    

        my_file = drive.CreateFile({'id': file_id})
        my_file.SetContentFile(os.path.join(dir_path))
        my_file.Upload()
        
        return "success";
    
    
def main():
    # print(create_and_upload_file(file_name='hello.txt', file_content='Hello Friend'))
    print(upload_dir('D:/Apps/CompP/build-__oop-Desktop_Qt_5_9_9_MinGW_32bit-Debug/auth.json', '1fth2612ds'))
    print(upload_dir('D:/Apps/CompP/build-__oop-Desktop_Qt_5_9_9_MinGW_32bit-Debug/activities.json', '2fth2612ds'))    
    print(upload_dir('D:/Apps/CompP/build-__oop-Desktop_Qt_5_9_9_MinGW_32bit-Debug/stats.json', '3fth2612ds'))    
    print(upload_dir('D:/Apps/CompP/build-__oop-Desktop_Qt_5_9_9_MinGW_32bit-Debug/timers.json', '4fth2612ds'))
    print(upload_dir('D:/Apps/CompP/build-__oop-Desktop_Qt_5_9_9_MinGW_32bit-Debug/users.json', '5fth2612ds'))
if __name__ =='__main__':
    main()