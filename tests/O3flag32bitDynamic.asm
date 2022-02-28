Disassembly of section .init:

00001000 <.init>:
	0x1000: 		f3 0f 1e fb                 	 endbr32       
	0x1004: 		53                          	 push          ebx
	0x1005: 		83 ec 08                    	 sub           esp, 8
	0x1008: 		e8 03 02 00 00              	 call          0x1210
	0x100d: 		81 c3 f3 2f 00 00           	 add           ebx, 0x2ff3
	0x1013: 		8b 83 f4 ff ff ff           	 mov           eax, dword ptr [ebx - 0xc]
	0x1019: 		85 c0                       	 test          eax, eax
	0x101b: 		74 02                       	 je            0x101f
	0x101d: 		ff d0                       	 call          eax
	0x101f: 		83 c4 08                    	 add           esp, 8
	0x1022: 		5b                          	 pop           ebx
	0x1023: 		c3                          	 ret           

Disassembly of section .plt:

00001030 <.plt>:
	0x1030: 		ff b3 04 00 00 00           	 push          dword ptr [ebx + 4]
	0x1036: 		ff a3 08 00 00 00           	 jmp           dword ptr [ebx + 8]
	0x103c: 		00 00                       	 add           byte ptr [eax], al
	0x103e: 		00 00                       	 add           byte ptr [eax], al
	0x1040: 		ff a3 0c 00 00 00           	 jmp           dword ptr [ebx + 0xc]
	0x1046: 		68 00 00 00 00              	 push          0
	0x104b: 		e9 e0 ff ff ff              	 jmp           0x1030
	0x1050: 		ff a3 10 00 00 00           	 jmp           dword ptr [ebx + 0x10]
	0x1056: 		68 08 00 00 00              	 push          8
	0x105b: 		e9 d0 ff ff ff              	 jmp           0x1030
	0x1060: 		ff a3 14 00 00 00           	 jmp           dword ptr [ebx + 0x14]
	0x1066: 		68 10 00 00 00              	 push          0x10
	0x106b: 		e9 c0 ff ff ff              	 jmp           0x1030

Disassembly of section .text:

00001070 <.text>:
	0x1070: 		8d 4c 24 04                 	 lea           ecx, [esp + 4]
	0x1074: 		83 e4 f0                    	 and           esp, 0xfffffff0
	0x1077: 		ff 71 fc                    	 push          dword ptr [ecx - 4]
	0x107a: 		55                          	 push          ebp
	0x107b: 		89 e5                       	 mov           ebp, esp
	0x107d: 		57                          	 push          edi
	0x107e: 		56                          	 push          esi
	0x107f: 		53                          	 push          ebx
	0x1080: 		e8 8b 01 00 00              	 call          0x1210
	0x1085: 		81 c3 7b 2f 00 00           	 add           ebx, 0x2f7b
	0x108b: 		51                          	 push          ecx
	0x108c: 		83 ec 18                    	 sub           esp, 0x18
	0x108f: 		e8 ac 02 00 00              	 call          0x1340
	0x1094: 		83 ec 0c                    	 sub           esp, 0xc
	0x1097: 		8d b3 15 e0 ff ff           	 lea           esi, [ebx - 0x1feb]
	0x109d: 		8d bb 21 e0 ff ff           	 lea           edi, [ebx - 0x1fdf]
	0x10a3: 		56                          	 push          esi
	0x10a4: 		e8 a7 ff ff ff              	 call          0x1050
	0x10a9: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x10ac: 		e8 9f ff ff ff              	 call          0x1050
	0x10b1: 		e8 8a 02 00 00              	 call          0x1340
	0x10b6: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x10b9: 		e8 92 ff ff ff              	 call          0x1050
	0x10be: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x10c1: 		e8 8a ff ff ff              	 call          0x1050
	0x10c6: 		e8 75 02 00 00              	 call          0x1340
	0x10cb: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x10ce: 		e8 6d ff ff ff              	 call          0x1040
	0x10d3: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x10d6: 		e8 65 ff ff ff              	 call          0x1040
	0x10db: 		8d 93 08 e0 ff ff           	 lea           edx, [ebx - 0x1ff8]
	0x10e1: 		89 14 24                    	 mov           dword ptr [esp], edx
	0x10e4: 		89 55 e4                    	 mov           dword ptr [ebp - 0x1c], edx
	0x10e7: 		e8 54 ff ff ff              	 call          0x1040
	0x10ec: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x10ef: 		e8 5c ff ff ff              	 call          0x1050
	0x10f4: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x10f7: 		e8 54 ff ff ff              	 call          0x1050
	0x10fc: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x10ff: 		e8 4c ff ff ff              	 call          0x1050
	0x1104: 		e8 37 02 00 00              	 call          0x1340
	0x1109: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x110c: 		e8 3f ff ff ff              	 call          0x1050
	0x1111: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1114: 		e8 37 ff ff ff              	 call          0x1050
	0x1119: 		e8 22 02 00 00              	 call          0x1340
	0x111e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1121: 		e8 2a ff ff ff              	 call          0x1050
	0x1126: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1129: 		e8 22 ff ff ff              	 call          0x1050
	0x112e: 		e8 0d 02 00 00              	 call          0x1340
	0x1133: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1136: 		e8 05 ff ff ff              	 call          0x1040
	0x113b: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x113e: 		e8 fd fe ff ff              	 call          0x1040
	0x1143: 		8b 55 e4                    	 mov           edx, dword ptr [ebp - 0x1c]
	0x1146: 		89 14 24                    	 mov           dword ptr [esp], edx
	0x1149: 		e8 f2 fe ff ff              	 call          0x1040
	0x114e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1151: 		e8 fa fe ff ff              	 call          0x1050
	0x1156: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1159: 		e8 f2 fe ff ff              	 call          0x1050
	0x115e: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1161: 		e8 ea fe ff ff              	 call          0x1050
	0x1166: 		e8 d5 01 00 00              	 call          0x1340
	0x116b: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x116e: 		e8 dd fe ff ff              	 call          0x1050
	0x1173: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1176: 		e8 d5 fe ff ff              	 call          0x1050
	0x117b: 		e8 c0 01 00 00              	 call          0x1340
	0x1180: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1183: 		e8 c8 fe ff ff              	 call          0x1050
	0x1188: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x118b: 		e8 c0 fe ff ff              	 call          0x1050
	0x1190: 		e8 ab 01 00 00              	 call          0x1340
	0x1195: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1198: 		e8 a3 fe ff ff              	 call          0x1040
	0x119d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x11a0: 		e8 9b fe ff ff              	 call          0x1040
	0x11a5: 		8b 55 e4                    	 mov           edx, dword ptr [ebp - 0x1c]
	0x11a8: 		89 14 24                    	 mov           dword ptr [esp], edx
	0x11ab: 		e8 90 fe ff ff              	 call          0x1040
	0x11b0: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x11b3: 		e8 98 fe ff ff              	 call          0x1050
	0x11b8: 		83 c4 10                    	 add           esp, 0x10
	0x11bb: 		8d 65 f0                    	 lea           esp, [ebp - 0x10]
	0x11be: 		31 c0                       	 xor           eax, eax
	0x11c0: 		59                          	 pop           ecx
	0x11c1: 		5b                          	 pop           ebx
	0x11c2: 		5e                          	 pop           esi
	0x11c3: 		5f                          	 pop           edi
	0x11c4: 		5d                          	 pop           ebp
	0x11c5: 		8d 61 fc                    	 lea           esp, [ecx - 4]
	0x11c8: 		c3                          	 ret           
	0x11c9: 		66 90                       	 nop           
	0x11cb: 		66 90                       	 nop           
	0x11cd: 		66 90                       	 nop           
	0x11cf: 		90                          	 nop           
	0x11d0: 		f3 0f 1e fb                 	 endbr32       
	0x11d4: 		31 ed                       	 xor           ebp, ebp
	0x11d6: 		5e                          	 pop           esi
	0x11d7: 		89 e1                       	 mov           ecx, esp
	0x11d9: 		83 e4 f0                    	 and           esp, 0xfffffff0
	0x11dc: 		50                          	 push          eax
	0x11dd: 		54                          	 push          esp
	0x11de: 		52                          	 push          edx
	0x11df: 		e8 22 00 00 00              	 call          0x1206
	0x11e4: 		81 c3 1c 2e 00 00           	 add           ebx, 0x2e1c
	0x11ea: 		8d 83 b0 dc ff ff           	 lea           eax, [ebx - 0x2350]
	0x11f0: 		50                          	 push          eax
	0x11f1: 		8d 83 40 dc ff ff           	 lea           eax, [ebx - 0x23c0]
	0x11f7: 		50                          	 push          eax
	0x11f8: 		51                          	 push          ecx
	0x11f9: 		56                          	 push          esi
	0x11fa: 		ff b3 f8 ff ff ff           	 push          dword ptr [ebx - 8]
	0x1200: 		e8 5b fe ff ff              	 call          0x1060
	0x1205: 		f4                          	 hlt           
	0x1206: 		8b 1c 24                    	 mov           ebx, dword ptr [esp]
	0x1209: 		c3                          	 ret           
	0x120a: 		66 90                       	 nop           
	0x120c: 		66 90                       	 nop           
	0x120e: 		66 90                       	 nop           
	0x1210: 		8b 1c 24                    	 mov           ebx, dword ptr [esp]
	0x1213: 		c3                          	 ret           
	0x1214: 		66 90                       	 nop           
	0x1216: 		66 90                       	 nop           
	0x1218: 		66 90                       	 nop           
	0x121a: 		66 90                       	 nop           
	0x121c: 		66 90                       	 nop           
	0x121e: 		66 90                       	 nop           
	0x1220: 		e8 e4 00 00 00              	 call          0x1309
	0x1225: 		81 c2 db 2d 00 00           	 add           edx, 0x2ddb
	0x122b: 		8d 8a 20 00 00 00           	 lea           ecx, [edx + 0x20]
	0x1231: 		8d 82 20 00 00 00           	 lea           eax, [edx + 0x20]
	0x1237: 		39 c8                       	 cmp           eax, ecx
	0x1239: 		74 1d                       	 je            0x1258
	0x123b: 		8b 82 ec ff ff ff           	 mov           eax, dword ptr [edx - 0x14]
	0x1241: 		85 c0                       	 test          eax, eax
	0x1243: 		74 13                       	 je            0x1258
	0x1245: 		55                          	 push          ebp
	0x1246: 		89 e5                       	 mov           ebp, esp
	0x1248: 		83 ec 14                    	 sub           esp, 0x14
	0x124b: 		51                          	 push          ecx
	0x124c: 		ff d0                       	 call          eax
	0x124e: 		83 c4 10                    	 add           esp, 0x10
	0x1251: 		c9                          	 leave         
	0x1252: 		c3                          	 ret           
	0x1253: 		8d 74 26 00                 	 lea           esi, [esi]
	0x1257: 		90                          	 nop           
	0x1258: 		c3                          	 ret           
	0x1259: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x1260: 		e8 a4 00 00 00              	 call          0x1309
	0x1265: 		81 c2 9b 2d 00 00           	 add           edx, 0x2d9b
	0x126b: 		55                          	 push          ebp
	0x126c: 		89 e5                       	 mov           ebp, esp
	0x126e: 		53                          	 push          ebx
	0x126f: 		8d 8a 20 00 00 00           	 lea           ecx, [edx + 0x20]
	0x1275: 		8d 82 20 00 00 00           	 lea           eax, [edx + 0x20]
	0x127b: 		83 ec 04                    	 sub           esp, 4
	0x127e: 		29 c8                       	 sub           eax, ecx
	0x1280: 		89 c3                       	 mov           ebx, eax
	0x1282: 		c1 e8 1f                    	 shr           eax, 0x1f
	0x1285: 		c1 fb 02                    	 sar           ebx, 2
	0x1288: 		01 d8                       	 add           eax, ebx
	0x128a: 		d1 f8                       	 sar           eax, 1
	0x128c: 		74 14                       	 je            0x12a2
	0x128e: 		8b 92 fc ff ff ff           	 mov           edx, dword ptr [edx - 4]
	0x1294: 		85 d2                       	 test          edx, edx
	0x1296: 		74 0a                       	 je            0x12a2
	0x1298: 		83 ec 08                    	 sub           esp, 8
	0x129b: 		50                          	 push          eax
	0x129c: 		51                          	 push          ecx
	0x129d: 		ff d2                       	 call          edx
	0x129f: 		83 c4 10                    	 add           esp, 0x10
	0x12a2: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x12a5: 		c9                          	 leave         
	0x12a6: 		c3                          	 ret           
	0x12a7: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x12ae: 		66 90                       	 nop           
	0x12b0: 		f3 0f 1e fb                 	 endbr32       
	0x12b4: 		55                          	 push          ebp
	0x12b5: 		89 e5                       	 mov           ebp, esp
	0x12b7: 		53                          	 push          ebx
	0x12b8: 		e8 53 ff ff ff              	 call          0x1210
	0x12bd: 		81 c3 43 2d 00 00           	 add           ebx, 0x2d43
	0x12c3: 		83 ec 04                    	 sub           esp, 4
	0x12c6: 		80 bb 20 00 00 00 00        	 cmp           byte ptr [ebx + 0x20], 0
	0x12cd: 		75 28                       	 jne           0x12f7
	0x12cf: 		8b 83 f0 ff ff ff           	 mov           eax, dword ptr [ebx - 0x10]
	0x12d5: 		85 c0                       	 test          eax, eax
	0x12d7: 		74 12                       	 je            0x12eb
	0x12d9: 		83 ec 0c                    	 sub           esp, 0xc
	0x12dc: 		ff b3 1c 00 00 00           	 push          dword ptr [ebx + 0x1c]
	0x12e2: 		ff 93 f0 ff ff ff           	 call          dword ptr [ebx - 0x10]
	0x12e8: 		83 c4 10                    	 add           esp, 0x10
	0x12eb: 		e8 30 ff ff ff              	 call          0x1220
	0x12f0: 		c6 83 20 00 00 00 01        	 mov           byte ptr [ebx + 0x20], 1
	0x12f7: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x12fa: 		c9                          	 leave         
	0x12fb: 		c3                          	 ret           
	0x12fc: 		8d 74 26 00                 	 lea           esi, [esi]
	0x1300: 		f3 0f 1e fb                 	 endbr32       
	0x1304: 		e9 57 ff ff ff              	 jmp           0x1260
	0x1309: 		8b 14 24                    	 mov           edx, dword ptr [esp]
	0x130c: 		c3                          	 ret           
	0x130d: 		66 90                       	 nop           
	0x130f: 		90                          	 nop           
	0x1310: 		53                          	 push          ebx
	0x1311: 		e8 fa fe ff ff              	 call          0x1210
	0x1316: 		81 c3 ea 2c 00 00           	 add           ebx, 0x2cea
	0x131c: 		83 ec 14                    	 sub           esp, 0x14
	0x131f: 		8d 83 08 e0 ff ff           	 lea           eax, [ebx - 0x1ff8]
	0x1325: 		50                          	 push          eax
	0x1326: 		e8 15 fd ff ff              	 call          0x1040
	0x132b: 		8d 83 15 e0 ff ff           	 lea           eax, [ebx - 0x1feb]
	0x1331: 		89 04 24                    	 mov           dword ptr [esp], eax
	0x1334: 		e8 17 fd ff ff              	 call          0x1050
	0x1339: 		83 c4 18                    	 add           esp, 0x18
	0x133c: 		31 c0                       	 xor           eax, eax
	0x133e: 		5b                          	 pop           ebx
	0x133f: 		c3                          	 ret           
	0x1340: 		55                          	 push          ebp
	0x1341: 		57                          	 push          edi
	0x1342: 		56                          	 push          esi
	0x1343: 		53                          	 push          ebx
	0x1344: 		e8 c7 fe ff ff              	 call          0x1210
	0x1349: 		81 c3 b7 2c 00 00           	 add           ebx, 0x2cb7
	0x134f: 		83 ec 0c                    	 sub           esp, 0xc
	0x1352: 		e8 e9 ff ff ff              	 call          0x1340
	0x1357: 		83 ec 0c                    	 sub           esp, 0xc
	0x135a: 		8d b3 15 e0 ff ff           	 lea           esi, [ebx - 0x1feb]
	0x1360: 		8d bb 21 e0 ff ff           	 lea           edi, [ebx - 0x1fdf]
	0x1366: 		56                          	 push          esi
	0x1367: 		8d ab 08 e0 ff ff           	 lea           ebp, [ebx - 0x1ff8]
	0x136d: 		e8 de fc ff ff              	 call          0x1050
	0x1372: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1375: 		e8 d6 fc ff ff              	 call          0x1050
	0x137a: 		e8 c1 ff ff ff              	 call          0x1340
	0x137f: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1382: 		e8 c9 fc ff ff              	 call          0x1050
	0x1387: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x138a: 		e8 c1 fc ff ff              	 call          0x1050
	0x138f: 		e8 ac ff ff ff              	 call          0x1340
	0x1394: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1397: 		e8 b4 fc ff ff              	 call          0x1050
	0x139c: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x139f: 		e8 ac fc ff ff              	 call          0x1050
	0x13a4: 		e8 97 ff ff ff              	 call          0x1340
	0x13a9: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x13ac: 		e8 8f fc ff ff              	 call          0x1040
	0x13b1: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x13b4: 		e8 87 fc ff ff              	 call          0x1040
	0x13b9: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x13bc: 		e8 7f fc ff ff              	 call          0x1040
	0x13c1: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x13c4: 		e8 87 fc ff ff              	 call          0x1050
	0x13c9: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x13cc: 		e8 7f fc ff ff              	 call          0x1050
	0x13d1: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x13d4: 		e8 77 fc ff ff              	 call          0x1050
	0x13d9: 		e8 62 ff ff ff              	 call          0x1340
	0x13de: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x13e1: 		e8 6a fc ff ff              	 call          0x1050
	0x13e6: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x13e9: 		e8 62 fc ff ff              	 call          0x1050
	0x13ee: 		e8 4d ff ff ff              	 call          0x1340
	0x13f3: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x13f6: 		e8 55 fc ff ff              	 call          0x1050
	0x13fb: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x13fe: 		e8 4d fc ff ff              	 call          0x1050
	0x1403: 		e8 38 ff ff ff              	 call          0x1340
	0x1408: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x140b: 		e8 30 fc ff ff              	 call          0x1040
	0x1410: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1413: 		e8 28 fc ff ff              	 call          0x1040
	0x1418: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x141b: 		e8 20 fc ff ff              	 call          0x1040
	0x1420: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1423: 		e8 28 fc ff ff              	 call          0x1050
	0x1428: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x142b: 		e8 10 fc ff ff              	 call          0x1040
	0x1430: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1433: 		e8 08 fc ff ff              	 call          0x1040
	0x1438: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x143b: 		e8 00 fc ff ff              	 call          0x1040
	0x1440: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1443: 		e8 08 fc ff ff              	 call          0x1050
	0x1448: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x144b: 		e8 00 fc ff ff              	 call          0x1050
	0x1450: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1453: 		e8 f8 fb ff ff              	 call          0x1050
	0x1458: 		e8 e3 fe ff ff              	 call          0x1340
	0x145d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1460: 		e8 eb fb ff ff              	 call          0x1050
	0x1465: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1468: 		e8 e3 fb ff ff              	 call          0x1050
	0x146d: 		e8 ce fe ff ff              	 call          0x1340
	0x1472: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1475: 		e8 d6 fb ff ff              	 call          0x1050
	0x147a: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x147d: 		e8 ce fb ff ff              	 call          0x1050
	0x1482: 		e8 b9 fe ff ff              	 call          0x1340
	0x1487: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x148a: 		e8 b1 fb ff ff              	 call          0x1040
	0x148f: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1492: 		e8 a9 fb ff ff              	 call          0x1040
	0x1497: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x149a: 		e8 a1 fb ff ff              	 call          0x1040
	0x149f: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x14a2: 		e8 a9 fb ff ff              	 call          0x1050
	0x14a7: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x14aa: 		e8 a1 fb ff ff              	 call          0x1050
	0x14af: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x14b2: 		e8 99 fb ff ff              	 call          0x1050
	0x14b7: 		e8 84 fe ff ff              	 call          0x1340
	0x14bc: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x14bf: 		e8 8c fb ff ff              	 call          0x1050
	0x14c4: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x14c7: 		e8 84 fb ff ff              	 call          0x1050
	0x14cc: 		e8 6f fe ff ff              	 call          0x1340
	0x14d1: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x14d4: 		e8 77 fb ff ff              	 call          0x1050
	0x14d9: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x14dc: 		e8 6f fb ff ff              	 call          0x1050
	0x14e1: 		e8 5a fe ff ff              	 call          0x1340
	0x14e6: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x14e9: 		e8 52 fb ff ff              	 call          0x1040
	0x14ee: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x14f1: 		e8 4a fb ff ff              	 call          0x1040
	0x14f6: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x14f9: 		e8 42 fb ff ff              	 call          0x1040
	0x14fe: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1501: 		e8 4a fb ff ff              	 call          0x1050
	0x1506: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1509: 		e8 32 fb ff ff              	 call          0x1040
	0x150e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1511: 		e8 2a fb ff ff              	 call          0x1040
	0x1516: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1519: 		e8 22 fb ff ff              	 call          0x1040
	0x151e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1521: 		e8 2a fb ff ff              	 call          0x1050
	0x1526: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1529: 		e8 22 fb ff ff              	 call          0x1050
	0x152e: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1531: 		e8 1a fb ff ff              	 call          0x1050
	0x1536: 		e8 05 fe ff ff              	 call          0x1340
	0x153b: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x153e: 		e8 0d fb ff ff              	 call          0x1050
	0x1543: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1546: 		e8 05 fb ff ff              	 call          0x1050
	0x154b: 		e8 f0 fd ff ff              	 call          0x1340
	0x1550: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1553: 		e8 f8 fa ff ff              	 call          0x1050
	0x1558: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x155b: 		e8 f0 fa ff ff              	 call          0x1050
	0x1560: 		e8 db fd ff ff              	 call          0x1340
	0x1565: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1568: 		e8 d3 fa ff ff              	 call          0x1040
	0x156d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1570: 		e8 cb fa ff ff              	 call          0x1040
	0x1575: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1578: 		e8 c3 fa ff ff              	 call          0x1040
	0x157d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1580: 		e8 cb fa ff ff              	 call          0x1050
	0x1585: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1588: 		e8 c3 fa ff ff              	 call          0x1050
	0x158d: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1590: 		e8 bb fa ff ff              	 call          0x1050
	0x1595: 		e8 a6 fd ff ff              	 call          0x1340
	0x159a: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x159d: 		e8 ae fa ff ff              	 call          0x1050
	0x15a2: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x15a5: 		e8 a6 fa ff ff              	 call          0x1050
	0x15aa: 		e8 91 fd ff ff              	 call          0x1340
	0x15af: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x15b2: 		e8 99 fa ff ff              	 call          0x1050
	0x15b7: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x15ba: 		e8 91 fa ff ff              	 call          0x1050
	0x15bf: 		e8 7c fd ff ff              	 call          0x1340
	0x15c4: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x15c7: 		e8 84 fa ff ff              	 call          0x1050
	0x15cc: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x15cf: 		e8 7c fa ff ff              	 call          0x1050
	0x15d4: 		e8 67 fd ff ff              	 call          0x1340
	0x15d9: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x15dc: 		e8 5f fa ff ff              	 call          0x1040
	0x15e1: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x15e4: 		e8 57 fa ff ff              	 call          0x1040
	0x15e9: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x15ec: 		e8 4f fa ff ff              	 call          0x1040
	0x15f1: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x15f4: 		e8 57 fa ff ff              	 call          0x1050
	0x15f9: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x15fc: 		e8 4f fa ff ff              	 call          0x1050
	0x1601: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1604: 		e8 47 fa ff ff              	 call          0x1050
	0x1609: 		e8 32 fd ff ff              	 call          0x1340
	0x160e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1611: 		e8 3a fa ff ff              	 call          0x1050
	0x1616: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1619: 		e8 32 fa ff ff              	 call          0x1050
	0x161e: 		e8 1d fd ff ff              	 call          0x1340
	0x1623: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1626: 		e8 25 fa ff ff              	 call          0x1050
	0x162b: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x162e: 		e8 1d fa ff ff              	 call          0x1050
	0x1633: 		e8 08 fd ff ff              	 call          0x1340
	0x1638: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x163b: 		e8 00 fa ff ff              	 call          0x1040
	0x1640: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1643: 		e8 f8 f9 ff ff              	 call          0x1040
	0x1648: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x164b: 		e8 f0 f9 ff ff              	 call          0x1040
	0x1650: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1653: 		e8 f8 f9 ff ff              	 call          0x1050
	0x1658: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x165b: 		e8 e0 f9 ff ff              	 call          0x1040
	0x1660: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1663: 		e8 d8 f9 ff ff              	 call          0x1040
	0x1668: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x166b: 		e8 d0 f9 ff ff              	 call          0x1040
	0x1670: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1673: 		e8 d8 f9 ff ff              	 call          0x1050
	0x1678: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x167b: 		e8 d0 f9 ff ff              	 call          0x1050
	0x1680: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1683: 		e8 c8 f9 ff ff              	 call          0x1050
	0x1688: 		e8 b3 fc ff ff              	 call          0x1340
	0x168d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1690: 		e8 bb f9 ff ff              	 call          0x1050
	0x1695: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1698: 		e8 b3 f9 ff ff              	 call          0x1050
	0x169d: 		e8 9e fc ff ff              	 call          0x1340
	0x16a2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x16a5: 		e8 a6 f9 ff ff              	 call          0x1050
	0x16aa: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x16ad: 		e8 9e f9 ff ff              	 call          0x1050
	0x16b2: 		e8 89 fc ff ff              	 call          0x1340
	0x16b7: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x16ba: 		e8 91 f9 ff ff              	 call          0x1050
	0x16bf: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x16c2: 		e8 89 f9 ff ff              	 call          0x1050
	0x16c7: 		e8 74 fc ff ff              	 call          0x1340
	0x16cc: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x16cf: 		e8 6c f9 ff ff              	 call          0x1040
	0x16d4: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x16d7: 		e8 64 f9 ff ff              	 call          0x1040
	0x16dc: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x16df: 		e8 5c f9 ff ff              	 call          0x1040
	0x16e4: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x16e7: 		e8 64 f9 ff ff              	 call          0x1050
	0x16ec: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x16ef: 		e8 5c f9 ff ff              	 call          0x1050
	0x16f4: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x16f7: 		e8 54 f9 ff ff              	 call          0x1050
	0x16fc: 		e8 3f fc ff ff              	 call          0x1340
	0x1701: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1704: 		e8 37 f9 ff ff              	 call          0x1040
	0x1709: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x170c: 		e8 2f f9 ff ff              	 call          0x1040
	0x1711: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1714: 		e8 27 f9 ff ff              	 call          0x1040
	0x1719: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x171c: 		e8 2f f9 ff ff              	 call          0x1050
	0x1721: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1724: 		e8 17 f9 ff ff              	 call          0x1040
	0x1729: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x172c: 		e8 0f f9 ff ff              	 call          0x1040
	0x1731: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1734: 		e8 07 f9 ff ff              	 call          0x1040
	0x1739: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x173c: 		e8 0f f9 ff ff              	 call          0x1050
	0x1741: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1744: 		e8 07 f9 ff ff              	 call          0x1050
	0x1749: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x174c: 		e8 ff f8 ff ff              	 call          0x1050
	0x1751: 		e8 ea fb ff ff              	 call          0x1340
	0x1756: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1759: 		e8 f2 f8 ff ff              	 call          0x1050
	0x175e: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1761: 		e8 ea f8 ff ff              	 call          0x1050
	0x1766: 		e8 d5 fb ff ff              	 call          0x1340
	0x176b: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x176e: 		e8 dd f8 ff ff              	 call          0x1050
	0x1773: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1776: 		e8 d5 f8 ff ff              	 call          0x1050
	0x177b: 		e8 c0 fb ff ff              	 call          0x1340
	0x1780: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1783: 		e8 c8 f8 ff ff              	 call          0x1050
	0x1788: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x178b: 		e8 c0 f8 ff ff              	 call          0x1050
	0x1790: 		e8 ab fb ff ff              	 call          0x1340
	0x1795: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1798: 		e8 a3 f8 ff ff              	 call          0x1040
	0x179d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17a0: 		e8 9b f8 ff ff              	 call          0x1040
	0x17a5: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x17a8: 		e8 93 f8 ff ff              	 call          0x1040
	0x17ad: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17b0: 		e8 9b f8 ff ff              	 call          0x1050
	0x17b5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17b8: 		e8 93 f8 ff ff              	 call          0x1050
	0x17bd: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x17c0: 		e8 8b f8 ff ff              	 call          0x1050
	0x17c5: 		e8 76 fb ff ff              	 call          0x1340
	0x17ca: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17cd: 		e8 6e f8 ff ff              	 call          0x1040
	0x17d2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17d5: 		e8 66 f8 ff ff              	 call          0x1040
	0x17da: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x17dd: 		e8 5e f8 ff ff              	 call          0x1040
	0x17e2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17e5: 		e8 66 f8 ff ff              	 call          0x1050
	0x17ea: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x17ed: 		e8 5e f8 ff ff              	 call          0x1050
	0x17f2: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x17f5: 		e8 56 f8 ff ff              	 call          0x1050
	0x17fa: 		e8 41 fb ff ff              	 call          0x1340
	0x17ff: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1802: 		e8 49 f8 ff ff              	 call          0x1050
	0x1807: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x180a: 		e8 41 f8 ff ff              	 call          0x1050
	0x180f: 		e8 2c fb ff ff              	 call          0x1340
	0x1814: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1817: 		e8 34 f8 ff ff              	 call          0x1050
	0x181c: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x181f: 		e8 2c f8 ff ff              	 call          0x1050
	0x1824: 		e8 17 fb ff ff              	 call          0x1340
	0x1829: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x182c: 		e8 1f f8 ff ff              	 call          0x1050
	0x1831: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1834: 		e8 17 f8 ff ff              	 call          0x1050
	0x1839: 		e8 02 fb ff ff              	 call          0x1340
	0x183e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1841: 		e8 fa f7 ff ff              	 call          0x1040
	0x1846: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1849: 		e8 f2 f7 ff ff              	 call          0x1040
	0x184e: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1851: 		e8 ea f7 ff ff              	 call          0x1040
	0x1856: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1859: 		e8 f2 f7 ff ff              	 call          0x1050
	0x185e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1861: 		e8 ea f7 ff ff              	 call          0x1050
	0x1866: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1869: 		e8 e2 f7 ff ff              	 call          0x1050
	0x186e: 		e8 cd fa ff ff              	 call          0x1340
	0x1873: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1876: 		e8 d5 f7 ff ff              	 call          0x1050
	0x187b: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x187e: 		e8 cd f7 ff ff              	 call          0x1050
	0x1883: 		e8 b8 fa ff ff              	 call          0x1340
	0x1888: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x188b: 		e8 c0 f7 ff ff              	 call          0x1050
	0x1890: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1893: 		e8 b8 f7 ff ff              	 call          0x1050
	0x1898: 		e8 a3 fa ff ff              	 call          0x1340
	0x189d: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18a0: 		e8 9b f7 ff ff              	 call          0x1040
	0x18a5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18a8: 		e8 93 f7 ff ff              	 call          0x1040
	0x18ad: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x18b0: 		e8 8b f7 ff ff              	 call          0x1040
	0x18b5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18b8: 		e8 93 f7 ff ff              	 call          0x1050
	0x18bd: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18c0: 		e8 7b f7 ff ff              	 call          0x1040
	0x18c5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18c8: 		e8 73 f7 ff ff              	 call          0x1040
	0x18cd: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x18d0: 		e8 6b f7 ff ff              	 call          0x1040
	0x18d5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18d8: 		e8 73 f7 ff ff              	 call          0x1050
	0x18dd: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18e0: 		e8 6b f7 ff ff              	 call          0x1050
	0x18e5: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x18e8: 		e8 63 f7 ff ff              	 call          0x1050
	0x18ed: 		e8 4e fa ff ff              	 call          0x1340
	0x18f2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x18f5: 		e8 56 f7 ff ff              	 call          0x1050
	0x18fa: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x18fd: 		e8 4e f7 ff ff              	 call          0x1050
	0x1902: 		e8 39 fa ff ff              	 call          0x1340
	0x1907: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x190a: 		e8 41 f7 ff ff              	 call          0x1050
	0x190f: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1912: 		e8 39 f7 ff ff              	 call          0x1050
	0x1917: 		e8 24 fa ff ff              	 call          0x1340
	0x191c: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x191f: 		e8 1c f7 ff ff              	 call          0x1040
	0x1924: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1927: 		e8 14 f7 ff ff              	 call          0x1040
	0x192c: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x192f: 		e8 0c f7 ff ff              	 call          0x1040
	0x1934: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1937: 		e8 14 f7 ff ff              	 call          0x1050
	0x193c: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x193f: 		e8 0c f7 ff ff              	 call          0x1050
	0x1944: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1947: 		e8 04 f7 ff ff              	 call          0x1050
	0x194c: 		e8 ef f9 ff ff              	 call          0x1340
	0x1951: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1954: 		e8 f7 f6 ff ff              	 call          0x1050
	0x1959: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x195c: 		e8 ef f6 ff ff              	 call          0x1050
	0x1961: 		e8 da f9 ff ff              	 call          0x1340
	0x1966: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1969: 		e8 e2 f6 ff ff              	 call          0x1050
	0x196e: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1971: 		e8 da f6 ff ff              	 call          0x1050
	0x1976: 		e8 c5 f9 ff ff              	 call          0x1340
	0x197b: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x197e: 		e8 bd f6 ff ff              	 call          0x1040
	0x1983: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1986: 		e8 b5 f6 ff ff              	 call          0x1040
	0x198b: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x198e: 		e8 ad f6 ff ff              	 call          0x1040
	0x1993: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1996: 		e8 b5 f6 ff ff              	 call          0x1050
	0x199b: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x199e: 		e8 ad f6 ff ff              	 call          0x1050
	0x19a3: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x19a6: 		e8 a5 f6 ff ff              	 call          0x1050
	0x19ab: 		e8 90 f9 ff ff              	 call          0x1340
	0x19b0: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x19b3: 		e8 98 f6 ff ff              	 call          0x1050
	0x19b8: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x19bb: 		e8 90 f6 ff ff              	 call          0x1050
	0x19c0: 		e8 7b f9 ff ff              	 call          0x1340
	0x19c5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x19c8: 		e8 83 f6 ff ff              	 call          0x1050
	0x19cd: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x19d0: 		e8 7b f6 ff ff              	 call          0x1050
	0x19d5: 		e8 66 f9 ff ff              	 call          0x1340
	0x19da: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x19dd: 		e8 5e f6 ff ff              	 call          0x1040
	0x19e2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x19e5: 		e8 56 f6 ff ff              	 call          0x1040
	0x19ea: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x19ed: 		e8 4e f6 ff ff              	 call          0x1040
	0x19f2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x19f5: 		e8 56 f6 ff ff              	 call          0x1050
	0x19fa: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x19fd: 		e8 3e f6 ff ff              	 call          0x1040
	0x1a02: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a05: 		e8 36 f6 ff ff              	 call          0x1040
	0x1a0a: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1a0d: 		e8 2e f6 ff ff              	 call          0x1040
	0x1a12: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a15: 		e8 36 f6 ff ff              	 call          0x1050
	0x1a1a: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a1d: 		e8 1e f6 ff ff              	 call          0x1040
	0x1a22: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a25: 		e8 16 f6 ff ff              	 call          0x1040
	0x1a2a: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1a2d: 		e8 0e f6 ff ff              	 call          0x1040
	0x1a32: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a35: 		e8 16 f6 ff ff              	 call          0x1050
	0x1a3a: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a3d: 		e8 fe f5 ff ff              	 call          0x1040
	0x1a42: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a45: 		e8 f6 f5 ff ff              	 call          0x1040
	0x1a4a: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1a4d: 		e8 ee f5 ff ff              	 call          0x1040
	0x1a52: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1a55: 		e8 f6 f5 ff ff              	 call          0x1050
	0x1a5a: 		83 c4 1c                    	 add           esp, 0x1c
	0x1a5d: 		31 c0                       	 xor           eax, eax
	0x1a5f: 		5b                          	 pop           ebx
	0x1a60: 		5e                          	 pop           esi
	0x1a61: 		5f                          	 pop           edi
	0x1a62: 		5d                          	 pop           ebp
	0x1a63: 		c3                          	 ret           
	0x1a64: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x1a6b: 		8d 74 26 00                 	 lea           esi, [esi]
	0x1a6f: 		90                          	 nop           
	0x1a70: 		57                          	 push          edi
	0x1a71: 		56                          	 push          esi
	0x1a72: 		53                          	 push          ebx
	0x1a73: 		e8 98 f7 ff ff              	 call          0x1210
	0x1a78: 		81 c3 88 25 00 00           	 add           ebx, 0x2588
	0x1a7e: 		e8 bd f8 ff ff              	 call          0x1340
	0x1a83: 		83 ec 0c                    	 sub           esp, 0xc
	0x1a86: 		8d b3 15 e0 ff ff           	 lea           esi, [ebx - 0x1feb]
	0x1a8c: 		8d bb 21 e0 ff ff           	 lea           edi, [ebx - 0x1fdf]
	0x1a92: 		56                          	 push          esi
	0x1a93: 		e8 b8 f5 ff ff              	 call          0x1050
	0x1a98: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1a9b: 		e8 b0 f5 ff ff              	 call          0x1050
	0x1aa0: 		e8 9b f8 ff ff              	 call          0x1340
	0x1aa5: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1aa8: 		e8 a3 f5 ff ff              	 call          0x1050
	0x1aad: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1ab0: 		e8 9b f5 ff ff              	 call          0x1050
	0x1ab5: 		e8 86 f8 ff ff              	 call          0x1340
	0x1aba: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1abd: 		e8 7e f5 ff ff              	 call          0x1040
	0x1ac2: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1ac5: 		e8 76 f5 ff ff              	 call          0x1040
	0x1aca: 		8d 83 08 e0 ff ff           	 lea           eax, [ebx - 0x1ff8]
	0x1ad0: 		89 04 24                    	 mov           dword ptr [esp], eax
	0x1ad3: 		e8 68 f5 ff ff              	 call          0x1040
	0x1ad8: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1adb: 		e8 70 f5 ff ff              	 call          0x1050
	0x1ae0: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1ae3: 		e8 68 f5 ff ff              	 call          0x1050
	0x1ae8: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1aeb: 		e8 60 f5 ff ff              	 call          0x1050
	0x1af0: 		83 c4 10                    	 add           esp, 0x10
	0x1af3: 		31 c0                       	 xor           eax, eax
	0x1af5: 		5b                          	 pop           ebx
	0x1af6: 		5e                          	 pop           esi
	0x1af7: 		5f                          	 pop           edi
	0x1af8: 		c3                          	 ret           
	0x1af9: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x1b00: 		55                          	 push          ebp
	0x1b01: 		57                          	 push          edi
	0x1b02: 		56                          	 push          esi
	0x1b03: 		53                          	 push          ebx
	0x1b04: 		e8 07 f7 ff ff              	 call          0x1210
	0x1b09: 		81 c3 f7 24 00 00           	 add           ebx, 0x24f7
	0x1b0f: 		83 ec 0c                    	 sub           esp, 0xc
	0x1b12: 		e8 29 f8 ff ff              	 call          0x1340
	0x1b17: 		83 ec 0c                    	 sub           esp, 0xc
	0x1b1a: 		8d b3 15 e0 ff ff           	 lea           esi, [ebx - 0x1feb]
	0x1b20: 		8d bb 21 e0 ff ff           	 lea           edi, [ebx - 0x1fdf]
	0x1b26: 		56                          	 push          esi
	0x1b27: 		8d ab 08 e0 ff ff           	 lea           ebp, [ebx - 0x1ff8]
	0x1b2d: 		e8 1e f5 ff ff              	 call          0x1050
	0x1b32: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1b35: 		e8 16 f5 ff ff              	 call          0x1050
	0x1b3a: 		e8 01 f8 ff ff              	 call          0x1340
	0x1b3f: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1b42: 		e8 09 f5 ff ff              	 call          0x1050
	0x1b47: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1b4a: 		e8 01 f5 ff ff              	 call          0x1050
	0x1b4f: 		e8 ec f7 ff ff              	 call          0x1340
	0x1b54: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1b57: 		e8 e4 f4 ff ff              	 call          0x1040
	0x1b5c: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1b5f: 		e8 dc f4 ff ff              	 call          0x1040
	0x1b64: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1b67: 		e8 d4 f4 ff ff              	 call          0x1040
	0x1b6c: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1b6f: 		e8 dc f4 ff ff              	 call          0x1050
	0x1b74: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1b77: 		e8 d4 f4 ff ff              	 call          0x1050
	0x1b7c: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1b7f: 		e8 cc f4 ff ff              	 call          0x1050
	0x1b84: 		e8 b7 f7 ff ff              	 call          0x1340
	0x1b89: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1b8c: 		e8 bf f4 ff ff              	 call          0x1050
	0x1b91: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1b94: 		e8 b7 f4 ff ff              	 call          0x1050
	0x1b99: 		e8 a2 f7 ff ff              	 call          0x1340
	0x1b9e: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1ba1: 		e8 aa f4 ff ff              	 call          0x1050
	0x1ba6: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1ba9: 		e8 a2 f4 ff ff              	 call          0x1050
	0x1bae: 		e8 8d f7 ff ff              	 call          0x1340
	0x1bb3: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1bb6: 		e8 85 f4 ff ff              	 call          0x1040
	0x1bbb: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1bbe: 		e8 7d f4 ff ff              	 call          0x1040
	0x1bc3: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1bc6: 		e8 75 f4 ff ff              	 call          0x1040
	0x1bcb: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1bce: 		e8 7d f4 ff ff              	 call          0x1050
	0x1bd3: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1bd6: 		e8 75 f4 ff ff              	 call          0x1050
	0x1bdb: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1bde: 		e8 6d f4 ff ff              	 call          0x1050
	0x1be3: 		e8 58 f7 ff ff              	 call          0x1340
	0x1be8: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1beb: 		e8 60 f4 ff ff              	 call          0x1050
	0x1bf0: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1bf3: 		e8 58 f4 ff ff              	 call          0x1050
	0x1bf8: 		e8 43 f7 ff ff              	 call          0x1340
	0x1bfd: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1c00: 		e8 4b f4 ff ff              	 call          0x1050
	0x1c05: 		89 3c 24                    	 mov           dword ptr [esp], edi
	0x1c08: 		e8 43 f4 ff ff              	 call          0x1050
	0x1c0d: 		e8 2e f7 ff ff              	 call          0x1340
	0x1c12: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1c15: 		e8 26 f4 ff ff              	 call          0x1040
	0x1c1a: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1c1d: 		e8 1e f4 ff ff              	 call          0x1040
	0x1c22: 		89 2c 24                    	 mov           dword ptr [esp], ebp
	0x1c25: 		e8 16 f4 ff ff              	 call          0x1040
	0x1c2a: 		89 34 24                    	 mov           dword ptr [esp], esi
	0x1c2d: 		e8 1e f4 ff ff              	 call          0x1050
	0x1c32: 		83 c4 1c                    	 add           esp, 0x1c
	0x1c35: 		31 c0                       	 xor           eax, eax
	0x1c37: 		5b                          	 pop           ebx
	0x1c38: 		5e                          	 pop           esi
	0x1c39: 		5f                          	 pop           edi
	0x1c3a: 		5d                          	 pop           ebp
	0x1c3b: 		c3                          	 ret           
	0x1c3c: 		66 90                       	 nop           
	0x1c3e: 		66 90                       	 nop           
	0x1c40: 		f3 0f 1e fb                 	 endbr32       
	0x1c44: 		55                          	 push          ebp
	0x1c45: 		e8 6b 00 00 00              	 call          0x1cb5
	0x1c4a: 		81 c5 b6 23 00 00           	 add           ebp, 0x23b6
	0x1c50: 		57                          	 push          edi
	0x1c51: 		56                          	 push          esi
	0x1c52: 		53                          	 push          ebx
	0x1c53: 		83 ec 0c                    	 sub           esp, 0xc
	0x1c56: 		89 eb                       	 mov           ebx, ebp
	0x1c58: 		8b 7c 24 28                 	 mov           edi, dword ptr [esp + 0x28]
	0x1c5c: 		e8 9f f3 ff ff              	 call          0x1000
	0x1c61: 		8d 9d f8 fe ff ff           	 lea           ebx, [ebp - 0x108]
	0x1c67: 		8d 85 f4 fe ff ff           	 lea           eax, [ebp - 0x10c]
	0x1c6d: 		29 c3                       	 sub           ebx, eax
	0x1c6f: 		c1 fb 02                    	 sar           ebx, 2
	0x1c72: 		74 29                       	 je            0x1c9d
	0x1c74: 		31 f6                       	 xor           esi, esi
	0x1c76: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x1c7d: 		8d 76 00                    	 lea           esi, [esi]
	0x1c80: 		83 ec 04                    	 sub           esp, 4
	0x1c83: 		57                          	 push          edi
	0x1c84: 		ff 74 24 2c                 	 push          dword ptr [esp + 0x2c]
	0x1c88: 		ff 74 24 2c                 	 push          dword ptr [esp + 0x2c]
	0x1c8c: 		ff 94 b5 f4 fe ff ff        	 call          dword ptr [ebp + esi*4 - 0x10c]
	0x1c93: 		83 c6 01                    	 add           esi, 1
	0x1c96: 		83 c4 10                    	 add           esp, 0x10
	0x1c99: 		39 f3                       	 cmp           ebx, esi
	0x1c9b: 		75 e3                       	 jne           0x1c80
	0x1c9d: 		83 c4 0c                    	 add           esp, 0xc
	0x1ca0: 		5b                          	 pop           ebx
	0x1ca1: 		5e                          	 pop           esi
	0x1ca2: 		5f                          	 pop           edi
	0x1ca3: 		5d                          	 pop           ebp
	0x1ca4: 		c3                          	 ret           
	0x1ca5: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x1cac: 		8d 74 26 00                 	 lea           esi, [esi]
	0x1cb0: 		f3 0f 1e fb                 	 endbr32       
	0x1cb4: 		c3                          	 ret           
	0x1cb5: 		8b 2c 24                    	 mov           ebp, dword ptr [esp]
	0x1cb8: 		c3                          	 ret           

Disassembly of section .fini:

00001cbc <.fini>:
	0x1cbc: 		f3 0f 1e fb                 	 endbr32       
	0x1cc0: 		53                          	 push          ebx
	0x1cc1: 		83 ec 08                    	 sub           esp, 8
	0x1cc4: 		e8 47 f5 ff ff              	 call          0x1210
	0x1cc9: 		81 c3 37 23 00 00           	 add           ebx, 0x2337
	0x1ccf: 		83 c4 08                    	 add           esp, 8
	0x1cd2: 		5b                          	 pop           ebx
	0x1cd3: 		c3                          	 ret           

