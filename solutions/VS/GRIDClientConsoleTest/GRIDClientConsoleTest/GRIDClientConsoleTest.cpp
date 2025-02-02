// ConsoleApplication5.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "GSStream.h"
#include "GSProtocolKissB.h"
#include "GSGRIDClient.h"

using namespace std;

int main()
{
	std::cout << "c++ - GRID Server KissB protocol (Binary) implementation \n";

	GSGRIDClient client;
	if (client.connect("127.0.0.1", 60000))
	{
		cout << "connected !" << std::endl;

		cout << "test get infos" << std::endl;
		TGRIDProtocol_KB_SRV_PROCESS_API_INFO* a = client.infos();
		cout << a->GRIDArch << std::endl;
		cout << a->GRIDCompiler << std::endl;
		cout << a->GRIDServerName << std::endl;
		cout << a->GRIDServices << std::endl;
		cout << a->GRIDVersion << std::endl;
		cout << a->ServerGenuineName << std::endl;
		cout << a->ServerHostArchitecture << std::endl;
		cout << a->ServerHostCPUArchitecture << std::endl;
		cout << a->ServerHostOS << std::endl;
		cout << a->ServerHostOSBuild << std::endl;

		//cout << "test CPU level " << endl;
		//for (int I = 0; I < 10; I++) {
		//	cout << I << " : " << client.infoCPULevel() << endl;
		//	Sleep(100);
		//}

	}
	else
	{
		cout << client.lastError() << std::endl;
	}

	system("pause");
}




/*

string CST_SIGNATURE = u8"KissB_Grid_Protocol_V1";

	string IP = "127.0.0.1";


	GSMemoryStream buf;  //TGRIDProtocol_KB_CLT_NEGOCIATE--->
	//buf.writeUint32(0);
	buf.writeByte(1);  //Command connect (TKBCltCommand)
	buf.writeString(CST_SIGNATURE); //SIgneture UTF8
	buf.writeByte(1); //VERSION MAJOR
	buf.writeByte(0); //VERSION MINOR
	buf.writeByte(0); //FORMAT (0=Binary, 1=JSON)
	buf.writeByte(0); //COMPRESSION (0=none)
	buf.writeByte(0); //CYPHERING (0=none)

	//<---TGRIDProtocol_KB_SRV_NEGOCIATE_HALF_RESPONSE

	GSMemoryStream buf2;  //TGRIDProtocol_KB_CLT_NEGOCIATE_UP--->
	//buf.writeUint32(0);
	buf2.writeByte(2);  //Command connectup (TKBCltCommand)
	buf2.writeString("admin"); //username
	buf2.writeString("admin"); //password





	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	SOCKET sock;
	SOCKADDR_IN sin;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(60000);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	//bind(sock, (SOCKADDR *)&sin, sizeof(sin));
	connect(sock, (SOCKADDR *)&sin, sizeof(sin));

	send(sock, (const char*)buf.data(), buf.size(), 0);




	char* localBuffer = (char*)malloc(1024);
	int r = 0;
	uint32_t ll = 0;

	r = recv(sock, (char*)&ll, sizeof(ll), 0);
	ll = ntohl(ll);
	do
	{
		r = recv(sock, localBuffer, ll, 0);
		if (r > 0)
			printf("Bytes received: %d\n", r);
		else if (r == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (r > 0 && r<ll);


	GSMemoryStream reception;
	reception.loadFromBuffer(localBuffer, r);
	reception.seekStart();
	uint8_t header = reception.readByte(); //Header TKBCltCommand_FromServer
	uint8_t status = reception.readByte(); //Status (Pascal Boolean)
	string statusString = reception.readString(); //Status string (error case)


	if (status == 1)  //OK (Pascal boolean true)
	{
		GSMemoryStream* packet = new(GSMemoryStream);
		packet->writeUint32(htonl(buf2.size()));
		packet->loadFromStream(&buf2,false);

		r  = send(sock, (const char*)packet->data(), packet->size(), 0);
		delete packet;
		if (r > 0)
		   printf("Bytes sent: %d\n", r);
		else if (r == 0)
		  printf("Connection closed\n");
		else
		  printf("send failed: %d\n", WSAGetLastError());


		r = recv(sock, (char*)&ll, sizeof(ll), 0);
		ll = ntohl(ll);
		do
		{
			r = recv(sock, localBuffer, ll, 0);
			if (r > 0)
				printf("Bytes received: %d\n", r);
			else if (r == 0)
				printf("Connection closed\n");
			else
				printf("recv failed: %d\n", WSAGetLastError());
		} while (r > 0 && r < ll);



		reception.clear();
		reception.loadFromBuffer(localBuffer, r);
		reception.seekStart();
		uint8_t header = reception.readByte(); //Header TKBCltCommand_FromServer
		uint8_t status = reception.readByte(); //Status (Pascal Boolean)
		string statusString = reception.readString(); //Status string (error case)
		if (status == 1)  //OK (Pascal boolean true)
		{
			printf("connecion ok.");
		}
		else
		{
			string c = "connection error : " + statusString;
			printf(c.c_str());
		}

	}




	WSACleanup();
*/



