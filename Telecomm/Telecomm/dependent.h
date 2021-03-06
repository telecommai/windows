﻿#ifndef DEPENDENT_H
#define DEPENDENT_H


#ifdef Q_OS_WIN
#ifdef _DEBUG
#pragma comment(lib,"HttpNetWorkShareLibD.lib")         
#pragma comment(lib,"SqlLiteShareLibD.lib")             
#pragma comment(lib,"IMDataManagerShareLibD.lib")       
#pragma comment(lib,"LoginDatabaseOperaShareLibD.lib")  
#pragma comment(lib,"ScanQRLoginShareLibD.lib")			
#pragma comment(lib,"IMRequestBuddyInfoD.lib")          
#pragma comment(lib,"ReadAppConfigD.lib")				
#pragma comment(lib,"OPObjectManagerD.lib")             
#pragma comment(lib,"AlphabeticalSortSharedLibD.lib")   
#pragma comment(lib,"IMDataBaseOperaInfoD.lib")         
#pragma comment(lib,"IMSocketNetWorkShareLibD.lib")     
#pragma comment(lib,"IMSocketDataBaseShareLibD.lib")   
#pragma comment(lib,"SocketNetWorkShareLibD.lib")       
#pragma comment(lib,"OPWindowsManagerShareLibD.lib")    
#pragma comment(lib,"BaseUIShareLibD.lib")              
#pragma comment(lib,"ContactsWidgetShareLibD.lib")      
#pragma comment(lib,"NewMsgNotifyShareLibD.lib")	    
#pragma comment(lib,"ChatWidgetShareLibD.lib")          
#pragma comment(lib,"OPMainWidgetShareLibD.lib")        
#pragma comment(lib,"OPMainManagerShareLibD.lib")       
#pragma comment(lib,"IMDownLoadHeaderImgD.lib")         
#pragma comment(lib,"VideoPlayShareLibD.lib")           
#pragma comment(lib,"libzvc125.lib")                    
#pragma comment(lib,"shlwapi.lib")       
#pragma comment(lib,"UpdateShareLibD.lib")              
#pragma comment(lib,"libzbar-0.lib")
#pragma comment(lib,"eWalletLibD.lib")
#pragma comment(lib,"QRenCodeShareLibD.lib")
#pragma comment(lib,"libqrencodeD.lib")
#pragma comment(lib,"OPRecoveryWalletShareLibD.lib")
#pragma comment(lib,"CreateAddWidgetShareLibD.lib")
#pragma comment(lib,"OPDatebaseShareLibD.lib")
#pragma comment(lib,"OPDataManagerD.lib")
#pragma comment(lib,"OPRequestShareLibD.lib")
#pragma comment(lib,"ContactsProfileShareLibD.lib")
#pragma comment(lib,"HttpServerShareLibD.lib")
#pragma comment(lib,"ScreenCutShareLibD.lib")
#pragma comment(lib,"QxtGlobalShortCutD.lib")
#pragma comment(lib,"WebObjectShareLibD.lib")
#pragma comment(lib,"SettingsManagerShareLibD.lib")
#pragma comment(lib,"botan.lib")
#pragma comment(lib,"QtAVd1.lib")
#pragma comment(lib,"QtAVWidgetsd1.lib")
#else
#pragma comment(lib,"HttpNetWorkShareLib.lib")          
#pragma comment(lib,"SqlLiteShareLib.lib") 
#pragma comment(lib,"IMDataManagerShareLib.lib") 
#pragma comment(lib,"LoginDatabaseOperaShareLib.lib")   
#pragma comment(lib,"IMRequestBuddyInfo.lib")         
#pragma comment(lib,"ReadAppConfig.lib")				
#pragma comment(lib,"OPObjectManager.lib")         
#pragma comment(lib,"AlphabeticalSortSharedLib.lib")    
#pragma comment(lib,"IMDataBaseOperaInfo.lib")          
#pragma comment(lib,"IMSocketNetWorkShareLib.lib")        
#pragma comment(lib,"IMSocketDataBaseShareLib.lib")       
#pragma comment(lib,"SocketNetWorkShareLib.lib")  
#pragma comment(lib,"OPWindowsManagerShareLib.lib") 
#pragma comment(lib,"BaseUIShareLib.lib") 
#pragma comment(lib,"ContactsWidgetShareLib.lib") 
#pragma comment(lib,"NewMsgNotifyShareLib.lib")	      
#pragma comment(lib,"ChatWidgetShareLib.lib")
#pragma comment(lib,"OPMainWidgetShareLib.lib") 
#pragma comment(lib,"OPMainManagerShareLib.lib") 
#pragma comment(lib,"IMDownLoadHeaderImg.lib") 
#pragma comment(lib,"VideoPlayShareLib.lib")          
#pragma comment(lib,"libzvc125.lib")
#pragma comment(lib,"UpdateShareLib.lib")
#pragma comment(lib,"shlwapi.lib")       
#pragma comment(lib,"libzbar-0.lib")
#pragma comment(lib,"eWalletLib.lib")
#pragma comment(lib,"ScanQRLoginShareLib.lib")
#pragma comment(lib,"QRenCodeShareLib.lib")
#pragma comment(lib,"libqrencode.lib")
#pragma comment(lib,"OPRecoveryWalletShareLib.lib")
#pragma comment(lib,"CreateAddWidgetShareLib.lib")
#pragma comment(lib,"OPDatebaseShareLib.lib")
#pragma comment(lib,"OPDataManager.lib")
#pragma comment(lib,"OPRequestShareLib.lib")
#pragma comment(lib,"ContactsProfileShareLib.lib")
#pragma comment(lib,"HttpServerShareLib.lib")
#pragma comment(lib,"ScreenCutShareLib.lib")
#pragma comment(lib,"QxtGlobalShortCut.lib")
#pragma comment(lib,"WebObjectShareLib.lib")
#pragma comment(lib,"SettingsManagerShareLib.lib")
#pragma comment(lib,"botan.lib")
#pragma comment(lib,"QtAV1.lib")
#pragma comment(lib,"QtAVWidgets1.lib")
#endif
#endif

#endif // DEPENDENT_H