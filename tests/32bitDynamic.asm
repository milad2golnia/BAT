Disassembly of section .init:

00001000 <.init>:
	0x1000: 		f3 0f 1e fb                 	 endbr32       
	0x1004: 		53                          	 push          ebx
	0x1005: 		83 ec 08                    	 sub           esp, 8
	0x1008: 		e8 a3 00 00 00              	 call          0x10b0
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
	0x1070: 		f3 0f 1e fb                 	 endbr32       
	0x1074: 		31 ed                       	 xor           ebp, ebp
	0x1076: 		5e                          	 pop           esi
	0x1077: 		89 e1                       	 mov           ecx, esp
	0x1079: 		83 e4 f0                    	 and           esp, 0xfffffff0
	0x107c: 		50                          	 push          eax
	0x107d: 		54                          	 push          esp
	0x107e: 		52                          	 push          edx
	0x107f: 		e8 22 00 00 00              	 call          0x10a6
	0x1084: 		81 c3 7c 2f 00 00           	 add           ebx, 0x2f7c
	0x108a: 		8d 83 40 d3 ff ff           	 lea           eax, [ebx - 0x2cc0]
	0x1090: 		50                          	 push          eax
	0x1091: 		8d 83 d0 d2 ff ff           	 lea           eax, [ebx - 0x2d30]
	0x1097: 		50                          	 push          eax
	0x1098: 		51                          	 push          ecx
	0x1099: 		56                          	 push          esi
	0x109a: 		ff b3 f8 ff ff ff           	 push          dword ptr [ebx - 8]
	0x10a0: 		e8 bb ff ff ff              	 call          0x1060
	0x10a5: 		f4                          	 hlt           
	0x10a6: 		8b 1c 24                    	 mov           ebx, dword ptr [esp]
	0x10a9: 		c3                          	 ret           
	0x10aa: 		66 90                       	 nop           
	0x10ac: 		66 90                       	 nop           
	0x10ae: 		66 90                       	 nop           
	0x10b0: 		8b 1c 24                    	 mov           ebx, dword ptr [esp]
	0x10b3: 		c3                          	 ret           
	0x10b4: 		66 90                       	 nop           
	0x10b6: 		66 90                       	 nop           
	0x10b8: 		66 90                       	 nop           
	0x10ba: 		66 90                       	 nop           
	0x10bc: 		66 90                       	 nop           
	0x10be: 		66 90                       	 nop           
	0x10c0: 		e8 e4 00 00 00              	 call          0x11a9
	0x10c5: 		81 c2 3b 2f 00 00           	 add           edx, 0x2f3b
	0x10cb: 		8d 8a 20 00 00 00           	 lea           ecx, [edx + 0x20]
	0x10d1: 		8d 82 20 00 00 00           	 lea           eax, [edx + 0x20]
	0x10d7: 		39 c8                       	 cmp           eax, ecx
	0x10d9: 		74 1d                       	 je            0x10f8
	0x10db: 		8b 82 ec ff ff ff           	 mov           eax, dword ptr [edx - 0x14]
	0x10e1: 		85 c0                       	 test          eax, eax
	0x10e3: 		74 13                       	 je            0x10f8
	0x10e5: 		55                          	 push          ebp
	0x10e6: 		89 e5                       	 mov           ebp, esp
	0x10e8: 		83 ec 14                    	 sub           esp, 0x14
	0x10eb: 		51                          	 push          ecx
	0x10ec: 		ff d0                       	 call          eax
	0x10ee: 		83 c4 10                    	 add           esp, 0x10
	0x10f1: 		c9                          	 leave         
	0x10f2: 		c3                          	 ret           
	0x10f3: 		8d 74 26 00                 	 lea           esi, [esi]
	0x10f7: 		90                          	 nop           
	0x10f8: 		c3                          	 ret           
	0x10f9: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x1100: 		e8 a4 00 00 00              	 call          0x11a9
	0x1105: 		81 c2 fb 2e 00 00           	 add           edx, 0x2efb
	0x110b: 		55                          	 push          ebp
	0x110c: 		89 e5                       	 mov           ebp, esp
	0x110e: 		53                          	 push          ebx
	0x110f: 		8d 8a 20 00 00 00           	 lea           ecx, [edx + 0x20]
	0x1115: 		8d 82 20 00 00 00           	 lea           eax, [edx + 0x20]
	0x111b: 		83 ec 04                    	 sub           esp, 4
	0x111e: 		29 c8                       	 sub           eax, ecx
	0x1120: 		89 c3                       	 mov           ebx, eax
	0x1122: 		c1 e8 1f                    	 shr           eax, 0x1f
	0x1125: 		c1 fb 02                    	 sar           ebx, 2
	0x1128: 		01 d8                       	 add           eax, ebx
	0x112a: 		d1 f8                       	 sar           eax, 1
	0x112c: 		74 14                       	 je            0x1142
	0x112e: 		8b 92 fc ff ff ff           	 mov           edx, dword ptr [edx - 4]
	0x1134: 		85 d2                       	 test          edx, edx
	0x1136: 		74 0a                       	 je            0x1142
	0x1138: 		83 ec 08                    	 sub           esp, 8
	0x113b: 		50                          	 push          eax
	0x113c: 		51                          	 push          ecx
	0x113d: 		ff d2                       	 call          edx
	0x113f: 		83 c4 10                    	 add           esp, 0x10
	0x1142: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x1145: 		c9                          	 leave         
	0x1146: 		c3                          	 ret           
	0x1147: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x114e: 		66 90                       	 nop           
	0x1150: 		f3 0f 1e fb                 	 endbr32       
	0x1154: 		55                          	 push          ebp
	0x1155: 		89 e5                       	 mov           ebp, esp
	0x1157: 		53                          	 push          ebx
	0x1158: 		e8 53 ff ff ff              	 call          0x10b0
	0x115d: 		81 c3 a3 2e 00 00           	 add           ebx, 0x2ea3
	0x1163: 		83 ec 04                    	 sub           esp, 4
	0x1166: 		80 bb 20 00 00 00 00        	 cmp           byte ptr [ebx + 0x20], 0
	0x116d: 		75 28                       	 jne           0x1197
	0x116f: 		8b 83 f0 ff ff ff           	 mov           eax, dword ptr [ebx - 0x10]
	0x1175: 		85 c0                       	 test          eax, eax
	0x1177: 		74 12                       	 je            0x118b
	0x1179: 		83 ec 0c                    	 sub           esp, 0xc
	0x117c: 		ff b3 1c 00 00 00           	 push          dword ptr [ebx + 0x1c]
	0x1182: 		ff 93 f0 ff ff ff           	 call          dword ptr [ebx - 0x10]
	0x1188: 		83 c4 10                    	 add           esp, 0x10
	0x118b: 		e8 30 ff ff ff              	 call          0x10c0
	0x1190: 		c6 83 20 00 00 00 01        	 mov           byte ptr [ebx + 0x20], 1
	0x1197: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x119a: 		c9                          	 leave         
	0x119b: 		c3                          	 ret           
	0x119c: 		8d 74 26 00                 	 lea           esi, [esi]
	0x11a0: 		f3 0f 1e fb                 	 endbr32       
	0x11a4: 		e9 57 ff ff ff              	 jmp           0x1100
	0x11a9: 		8b 14 24                    	 mov           edx, dword ptr [esp]
	0x11ac: 		c3                          	 ret           
	0x11ad: 		55                          	 push          ebp
	0x11ae: 		89 e5                       	 mov           ebp, esp
	0x11b0: 		53                          	 push          ebx
	0x11b1: 		83 ec 04                    	 sub           esp, 4
	0x11b4: 		e8 f7 fe ff ff              	 call          0x10b0
	0x11b9: 		81 c3 47 2e 00 00           	 add           ebx, 0x2e47
	0x11bf: 		83 ec 0c                    	 sub           esp, 0xc
	0x11c2: 		8d 83 08 e0 ff ff           	 lea           eax, [ebx - 0x1ff8]
	0x11c8: 		50                          	 push          eax
	0x11c9: 		e8 72 fe ff ff              	 call          0x1040
	0x11ce: 		83 c4 10                    	 add           esp, 0x10
	0x11d1: 		83 ec 0c                    	 sub           esp, 0xc
	0x11d4: 		8d 83 15 e0 ff ff           	 lea           eax, [ebx - 0x1feb]
	0x11da: 		50                          	 push          eax
	0x11db: 		e8 70 fe ff ff              	 call          0x1050
	0x11e0: 		83 c4 10                    	 add           esp, 0x10
	0x11e3: 		b8 00 00 00 00              	 mov           eax, 0
	0x11e8: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x11eb: 		c9                          	 leave         
	0x11ec: 		c3                          	 ret           
	0x11ed: 		55                          	 push          ebp
	0x11ee: 		89 e5                       	 mov           ebp, esp
	0x11f0: 		53                          	 push          ebx
	0x11f1: 		83 ec 04                    	 sub           esp, 4
	0x11f4: 		e8 b7 fe ff ff              	 call          0x10b0
	0x11f9: 		81 c3 07 2e 00 00           	 add           ebx, 0x2e07
	0x11ff: 		e8 78 00 00 00              	 call          0x127c
	0x1204: 		83 ec 0c                    	 sub           esp, 0xc
	0x1207: 		8d 83 15 e0 ff ff           	 lea           eax, [ebx - 0x1feb]
	0x120d: 		50                          	 push          eax
	0x120e: 		e8 2d fe ff ff              	 call          0x1040
	0x1213: 		83 c4 10                    	 add           esp, 0x10
	0x1216: 		83 ec 0c                    	 sub           esp, 0xc
	0x1219: 		8d 83 15 e0 ff ff           	 lea           eax, [ebx - 0x1feb]
	0x121f: 		50                          	 push          eax
	0x1220: 		e8 1b fe ff ff              	 call          0x1040
	0x1225: 		83 c4 10                    	 add           esp, 0x10
	0x1228: 		e8 80 ff ff ff              	 call          0x11ad
	0x122d: 		b8 00 00 00 00              	 mov           eax, 0
	0x1232: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x1235: 		c9                          	 leave         
	0x1236: 		c3                          	 ret           
	0x1237: 		55                          	 push          ebp
	0x1238: 		89 e5                       	 mov           ebp, esp
	0x123a: 		53                          	 push          ebx
	0x123b: 		83 ec 04                    	 sub           esp, 4
	0x123e: 		e8 6d fe ff ff              	 call          0x10b0
	0x1243: 		81 c3 bd 2d 00 00           	 add           ebx, 0x2dbd
	0x1249: 		e8 9f ff ff ff              	 call          0x11ed
	0x124e: 		83 ec 0c                    	 sub           esp, 0xc
	0x1251: 		8d 83 15 e0 ff ff           	 lea           eax, [ebx - 0x1feb]
	0x1257: 		50                          	 push          eax
	0x1258: 		e8 f3 fd ff ff              	 call          0x1050
	0x125d: 		83 c4 10                    	 add           esp, 0x10
	0x1260: 		83 ec 0c                    	 sub           esp, 0xc
	0x1263: 		8d 83 21 e0 ff ff           	 lea           eax, [ebx - 0x1fdf]
	0x1269: 		50                          	 push          eax
	0x126a: 		e8 e1 fd ff ff              	 call          0x1050
	0x126f: 		83 c4 10                    	 add           esp, 0x10
	0x1272: 		b8 00 00 00 00              	 mov           eax, 0
	0x1277: 		8b 5d fc                    	 mov           ebx, dword ptr [ebp - 4]
	0x127a: 		c9                          	 leave         
	0x127b: 		c3                          	 ret           
	0x127c: 		55                          	 push          ebp
	0x127d: 		89 e5                       	 mov           ebp, esp
	0x127f: 		83 ec 08                    	 sub           esp, 8
	0x1282: 		e8 37 00 00 00              	 call          0x12be
	0x1287: 		05 79 2d 00 00              	 add           eax, 0x2d79
	0x128c: 		e8 a6 ff ff ff              	 call          0x1237
	0x1291: 		e8 a1 ff ff ff              	 call          0x1237
	0x1296: 		e8 52 ff ff ff              	 call          0x11ed
	0x129b: 		b8 00 00 00 00              	 mov           eax, 0
	0x12a0: 		c9                          	 leave         
	0x12a1: 		c3                          	 ret           
	0x12a2: 		55                          	 push          ebp
	0x12a3: 		89 e5                       	 mov           ebp, esp
	0x12a5: 		83 e4 f0                    	 and           esp, 0xfffffff0
	0x12a8: 		e8 11 00 00 00              	 call          0x12be
	0x12ad: 		05 53 2d 00 00              	 add           eax, 0x2d53
	0x12b2: 		e8 c5 ff ff ff              	 call          0x127c
	0x12b7: 		b8 00 00 00 00              	 mov           eax, 0
	0x12bc: 		c9                          	 leave         
	0x12bd: 		c3                          	 ret           
	0x12be: 		8b 04 24                    	 mov           eax, dword ptr [esp]
	0x12c1: 		c3                          	 ret           
	0x12c2: 		66 90                       	 nop           
	0x12c4: 		66 90                       	 nop           
	0x12c6: 		66 90                       	 nop           
	0x12c8: 		66 90                       	 nop           
	0x12ca: 		66 90                       	 nop           
	0x12cc: 		66 90                       	 nop           
	0x12ce: 		66 90                       	 nop           
	0x12d0: 		f3 0f 1e fb                 	 endbr32       
	0x12d4: 		55                          	 push          ebp
	0x12d5: 		e8 6b 00 00 00              	 call          0x1345
	0x12da: 		81 c5 26 2d 00 00           	 add           ebp, 0x2d26
	0x12e0: 		57                          	 push          edi
	0x12e1: 		56                          	 push          esi
	0x12e2: 		53                          	 push          ebx
	0x12e3: 		83 ec 0c                    	 sub           esp, 0xc
	0x12e6: 		89 eb                       	 mov           ebx, ebp
	0x12e8: 		8b 7c 24 28                 	 mov           edi, dword ptr [esp + 0x28]
	0x12ec: 		e8 0f fd ff ff              	 call          0x1000
	0x12f1: 		8d 9d f8 fe ff ff           	 lea           ebx, [ebp - 0x108]
	0x12f7: 		8d 85 f4 fe ff ff           	 lea           eax, [ebp - 0x10c]
	0x12fd: 		29 c3                       	 sub           ebx, eax
	0x12ff: 		c1 fb 02                    	 sar           ebx, 2
	0x1302: 		74 29                       	 je            0x132d
	0x1304: 		31 f6                       	 xor           esi, esi
	0x1306: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x130d: 		8d 76 00                    	 lea           esi, [esi]
	0x1310: 		83 ec 04                    	 sub           esp, 4
	0x1313: 		57                          	 push          edi
	0x1314: 		ff 74 24 2c                 	 push          dword ptr [esp + 0x2c]
	0x1318: 		ff 74 24 2c                 	 push          dword ptr [esp + 0x2c]
	0x131c: 		ff 94 b5 f4 fe ff ff        	 call          dword ptr [ebp + esi*4 - 0x10c]
	0x1323: 		83 c6 01                    	 add           esi, 1
	0x1326: 		83 c4 10                    	 add           esp, 0x10
	0x1329: 		39 f3                       	 cmp           ebx, esi
	0x132b: 		75 e3                       	 jne           0x1310
	0x132d: 		83 c4 0c                    	 add           esp, 0xc
	0x1330: 		5b                          	 pop           ebx
	0x1331: 		5e                          	 pop           esi
	0x1332: 		5f                          	 pop           edi
	0x1333: 		5d                          	 pop           ebp
	0x1334: 		c3                          	 ret           
	0x1335: 		8d b4 26 00 00 00 00        	 lea           esi, [esi]
	0x133c: 		8d 74 26 00                 	 lea           esi, [esi]
	0x1340: 		f3 0f 1e fb                 	 endbr32       
	0x1344: 		c3                          	 ret           
	0x1345: 		8b 2c 24                    	 mov           ebp, dword ptr [esp]
	0x1348: 		c3                          	 ret           

Disassembly of section .fini:

0000134c <.fini>:
	0x134c: 		f3 0f 1e fb                 	 endbr32       
	0x1350: 		53                          	 push          ebx
	0x1351: 		83 ec 08                    	 sub           esp, 8
	0x1354: 		e8 57 fd ff ff              	 call          0x10b0
	0x1359: 		81 c3 a7 2c 00 00           	 add           ebx, 0x2ca7
	0x135f: 		83 c4 08                    	 add           esp, 8
	0x1362: 		5b                          	 pop           ebx
	0x1363: 		c3                          	 ret           

