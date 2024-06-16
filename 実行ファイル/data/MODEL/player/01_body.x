xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 248;
 -0.53040;77.52463;0.18340;,
 8.32330;77.20163;-8.67030;,
 -0.53040;77.20163;-12.33770;,
 -0.53040;77.52463;0.18340;,
 11.99070;77.20163;0.18340;,
 -0.53040;77.52463;0.18340;,
 8.32330;77.20163;9.03720;,
 -0.53040;77.52463;0.18340;,
 -0.53040;77.20163;12.70450;,
 -0.53040;77.52463;0.18340;,
 -9.38410;77.20163;9.03720;,
 -0.53040;77.52463;0.18340;,
 -13.05150;77.20163;0.18340;,
 -0.53040;77.52463;0.18340;,
 -9.38410;77.20163;-8.67030;,
 -0.53040;77.52463;0.18340;,
 -0.53040;77.20163;-12.33770;,
 15.82920;69.20683;-16.17610;,
 -0.53040;69.20683;-22.95250;,
 22.60560;69.20683;0.18340;,
 15.82920;69.20683;16.54300;,
 -0.53040;69.20683;23.31940;,
 -16.89010;69.20683;16.54300;,
 -23.66650;69.20683;0.18340;,
 -16.89010;69.20683;-16.17610;,
 -0.53040;69.20683;-22.95250;,
 18.59570;57.24243;-20.70180;,
 -0.53040;57.24243;-31.10130;,
 29.69810;57.24243;-0.17620;,
 20.84440;57.24243;26.17960;,
 -0.53040;57.24243;31.70780;,
 -21.90530;57.24243;26.17960;,
 -30.75900;57.24243;-0.17620;,
 -21.90530;57.24243;-22.70010;,
 -0.53040;57.24243;-31.10130;,
 32.18870;43.12913;-0.17620;,
 19.75660;43.12913;-23.62730;,
 22.60560;43.12913;24.92260;,
 -0.53040;43.12913;32.43000;,
 -23.66650;43.12913;25.26470;,
 -33.24960;43.12913;-0.17620;,
 -21.11060;43.12913;-25.67470;,
 -0.53040;43.12913;-31.38780;,
 -0.53040;43.12913;-31.38780;,
 26.76200;13.23883;-28.66570;,
 -0.53040;13.23883;-37.13880;,
 38.06650;13.23883;0.02230;,
 26.76200;13.23883;28.71020;,
 -0.53040;13.23883;37.54880;,
 -27.82280;13.23883;28.71020;,
 -39.12740;13.23883;0.02230;,
 -27.82280;13.23883;-28.66570;,
 -0.53040;13.23883;-37.13880;,
 20.35820;0.00643;-21.93460;,
 -0.53040;0.00643;-31.02940;,
 29.01060;0.00643;0.02230;,
 20.35820;0.00643;21.97910;,
 -0.53040;0.00643;31.07390;,
 -21.41910;0.00643;21.97910;,
 -30.07150;0.00643;0.02230;,
 -21.41910;0.00643;-21.93460;,
 -0.53040;0.00643;-31.02940;,
 10.77450;-0.62857;-11.86070;,
 -0.53040;-0.62857;-16.78280;,
 15.45710;-0.62857;0.02230;,
 10.77450;-0.62857;11.90520;,
 -0.53040;-0.62857;16.82730;,
 -11.83530;-0.62857;11.90520;,
 -16.51790;-0.62857;0.02230;,
 -11.83530;-0.62857;-11.86070;,
 -0.53040;-0.62857;-16.78280;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 -0.53040;-0.44957;0.02230;,
 37.96290;13.10293;0.84860;,
 39.38400;16.53383;0.84860;,
 27.59880;16.53383;-27.60340;,
 26.59400;13.10293;-26.59850;,
 42.81490;17.95493;0.84860;,
 30.02490;17.95493;-30.02930;,
 46.24580;16.53383;0.84860;,
 32.45090;16.53383;-32.45540;,
 47.66690;13.10293;0.84860;,
 33.45570;13.10293;-33.46020;,
 46.24580;9.67203;0.84860;,
 32.45090;9.67203;-32.45540;,
 42.81490;8.25103;0.84860;,
 30.02490;8.25103;-30.02930;,
 39.38400;9.67203;0.84860;,
 27.59880;9.67203;-27.60340;,
 37.96290;13.10293;0.84860;,
 26.59400;13.10293;-26.59850;,
 -0.85310;28.06613;-44.51920;,
 -0.85310;24.63523;-43.09810;,
 -0.85310;29.48713;-44.50540;,
 -0.85310;28.06613;-47.93630;,
 -0.85310;24.63523;-49.35740;,
 -0.85310;21.20423;-47.93630;,
 -0.85310;19.78323;-44.50540;,
 -0.85310;21.20423;-44.51920;,
 -0.85310;24.63523;-43.09810;,
 -29.30510;16.53383;-27.60340;,
 -28.30020;13.10293;-26.59850;,
 -31.73110;17.95493;-30.02930;,
 -34.15710;16.53383;-32.45540;,
 -35.16200;13.10293;-33.46020;,
 -34.15710;9.67203;-32.45540;,
 -31.73110;8.25103;-30.02930;,
 -29.30510;9.67203;-27.60340;,
 -28.30020;13.10293;-26.59850;,
 -41.09030;16.53383;0.84860;,
 -39.66930;13.10293;0.84860;,
 -44.52130;17.95493;0.84860;,
 -47.95210;16.53383;0.84860;,
 -49.37320;13.10293;0.84860;,
 -47.95210;9.67203;0.84860;,
 -44.52130;8.25103;0.84860;,
 -41.09030;9.67203;0.84860;,
 -39.66930;13.10293;0.84860;,
 -29.30510;16.53383;29.30060;,
 -28.30020;13.10293;28.29570;,
 -31.73110;17.95493;31.72650;,
 -34.15710;16.53383;34.15260;,
 -35.16200;13.10293;35.15740;,
 -34.15710;9.67203;34.15260;,
 -31.73110;8.25103;31.72650;,
 -29.30510;9.67203;29.30060;,
 -28.30020;13.10293;28.29570;,
 -0.85310;29.06733;46.58400;,
 -0.85310;25.63643;45.16290;,
 -0.85310;30.48843;47.12100;,
 -0.85310;29.06733;50.55190;,
 -0.85310;25.63643;51.97300;,
 -0.85310;22.20553;50.55190;,
 -0.85310;20.78443;47.12100;,
 -0.85310;22.20553;46.58400;,
 -0.85310;25.63643;45.16290;,
 27.59880;16.53383;29.30060;,
 26.59400;13.10293;28.29570;,
 30.02490;17.95493;31.72650;,
 32.45090;16.53383;34.15250;,
 33.45570;13.10293;35.15740;,
 32.45090;9.67203;34.15250;,
 30.02490;8.25103;31.72650;,
 27.59880;9.67203;29.30060;,
 26.59400;13.10293;28.29570;,
 39.38400;16.53383;0.84860;,
 37.96290;13.10293;0.84860;,
 42.81490;17.95493;0.84860;,
 46.24580;16.53383;0.84860;,
 47.66690;13.10293;0.84860;,
 46.24580;9.67203;0.84860;,
 42.81490;8.25103;0.84860;,
 39.38400;9.67203;0.84860;,
 37.96290;13.10293;0.84860;,
 -0.48080;89.78403;-0.01030;,
 11.91510;86.69293;-12.40640;,
 -0.48080;86.69293;-17.54100;,
 -0.48080;89.78403;-0.01030;,
 17.04980;86.69293;-0.01030;,
 -0.48080;89.78403;-0.01030;,
 11.91510;86.69293;12.38570;,
 -0.48080;89.78403;-0.01030;,
 -0.48090;86.69293;17.52030;,
 -0.48080;89.78403;-0.01030;,
 -12.87700;86.69293;12.38570;,
 -0.48080;89.78403;-0.01030;,
 -18.01170;86.69293;-0.01030;,
 -0.48080;89.78403;-0.01030;,
 -12.87700;86.69293;-12.40640;,
 -0.48080;89.78403;-0.01030;,
 -0.48080;86.69293;-17.54100;,
 22.81610;77.79233;-23.30730;,
 -0.48080;77.79233;-32.95730;,
 32.46600;77.79233;-0.01030;,
 22.81610;77.79233;23.28660;,
 -0.48090;77.79233;32.93660;,
 -23.77790;77.79233;23.28660;,
 -33.42800;77.79233;-0.01030;,
 -23.77790;77.79233;-23.30730;,
 -0.48080;77.79233;-32.95730;,
 30.90720;64.15573;-31.39830;,
 -0.48080;64.15573;-42.73910;,
 43.90840;64.15573;-0.01030;,
 30.90720;64.15573;31.37760;,
 -0.48090;64.15573;44.37890;,
 -31.86910;64.15573;31.37760;,
 -44.87030;64.15573;-0.01030;,
 -31.86910;64.15573;-31.39830;,
 -0.48080;64.15573;-42.73910;,
 35.21220;47.42833;-35.70340;,
 -0.48080;47.42833;-47.36320;,
 49.99670;47.42833;-0.01030;,
 35.21220;47.42833;35.68270;,
 -0.48090;47.42833;50.46730;,
 -36.17410;47.42833;35.68270;,
 -50.95860;47.42833;-0.01030;,
 -36.17410;47.42833;-35.70340;,
 -0.48080;47.42833;-47.36320;,
 35.21220;29.62723;-35.70340;,
 -0.48080;29.62723;-47.52960;,
 49.99670;29.62723;-0.01030;,
 35.21220;29.62723;35.68270;,
 -0.48090;29.62723;50.46730;,
 -36.17410;29.62723;35.68270;,
 -50.95860;29.62723;-0.01030;,
 -36.17410;29.62723;-35.70340;,
 -0.48080;29.62723;-47.52960;,
 30.90720;12.89963;-31.39830;,
 -0.48080;22.41943;-44.39960;,
 43.90840;12.89963;-0.01030;,
 30.90720;12.89963;31.37760;,
 -0.48090;22.41943;44.37890;,
 -31.86910;12.89963;31.37760;,
 -44.87030;12.89963;-0.01030;,
 -31.86910;12.89963;-31.39830;,
 -0.48080;22.41943;-44.39960;,
 22.81610;21.14753;-23.30730;,
 -0.48080;21.14753;-32.95730;,
 32.46600;11.62773;-0.01030;,
 22.81610;21.14753;23.28660;,
 -0.48090;21.14753;32.93660;,
 -23.77790;11.62773;23.28660;,
 -33.42800;11.62773;-0.01030;,
 -23.77790;11.62773;-23.30730;,
 -0.48080;21.14753;-32.95730;,
 11.91520;21.74883;-12.40640;,
 -0.48080;21.74883;-17.54110;,
 17.04980;21.74883;-0.01030;,
 11.91520;21.74883;12.38570;,
 -0.48090;21.74883;17.52040;,
 -12.87700;21.74883;12.38570;,
 -18.01170;21.74883;-0.01030;,
 -12.87700;21.74883;-12.40640;,
 -0.48080;21.74883;-17.54110;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;,
 -0.48080;21.14463;-0.01030;;
 
 199;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;26,28,35,36;,
 4;28,29,37,35;,
 4;29,30,38,37;,
 4;30,31,39,38;,
 4;31,32,40,39;,
 4;32,33,41,40;,
 4;33,34,42,41;,
 4;43,36,44,45;,
 4;36,35,46,44;,
 4;35,37,47,46;,
 4;37,38,48,47;,
 4;38,39,49,48;,
 4;39,40,50,49;,
 4;40,41,51,50;,
 4;41,42,52,51;,
 4;45,44,53,54;,
 4;44,46,55,53;,
 4;46,47,56,55;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;54,53,62,63;,
 4;53,55,64,62;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 3;63,62,71;,
 3;62,64,72;,
 3;64,65,73;,
 3;65,66,74;,
 3;66,67,75;,
 3;67,68,76;,
 3;68,69,77;,
 3;69,70,78;,
 4;79,80,81,82;,
 4;80,83,84,81;,
 4;83,85,86,84;,
 4;85,87,88,86;,
 4;87,89,90,88;,
 4;89,91,92,90;,
 4;91,93,94,92;,
 4;93,95,96,94;,
 4;82,81,97,98;,
 4;81,84,99,97;,
 4;84,86,100,99;,
 4;86,88,101,100;,
 4;88,90,102,101;,
 4;90,92,103,102;,
 4;92,94,104,103;,
 4;94,96,105,104;,
 4;98,97,106,107;,
 4;97,99,108,106;,
 4;99,100,109,108;,
 4;100,101,110,109;,
 4;101,102,111,110;,
 4;102,103,112,111;,
 4;103,104,113,112;,
 4;104,105,114,113;,
 4;107,106,115,116;,
 4;106,108,117,115;,
 4;108,109,118,117;,
 4;109,110,119,118;,
 4;110,111,120,119;,
 4;111,112,121,120;,
 4;112,113,122,121;,
 4;113,114,123,122;,
 4;116,115,124,125;,
 4;115,117,126,124;,
 4;117,118,127,126;,
 4;118,119,128,127;,
 4;119,120,129,128;,
 4;120,121,130,129;,
 4;121,122,131,130;,
 4;122,123,132,131;,
 4;125,124,133,134;,
 4;124,126,135,133;,
 4;126,127,136,135;,
 4;127,128,137,136;,
 4;128,129,138,137;,
 4;129,130,139,138;,
 4;130,131,140,139;,
 4;131,132,141,140;,
 4;134,133,142,143;,
 4;133,135,144,142;,
 4;135,136,145,144;,
 4;136,137,146,145;,
 4;137,138,147,146;,
 4;138,139,148,147;,
 4;139,140,149,148;,
 4;140,141,150,149;,
 4;143,142,151,152;,
 4;142,144,153,151;,
 4;144,145,154,153;,
 4;145,146,155,154;,
 4;146,147,156,155;,
 4;147,148,157,156;,
 4;148,149,158,157;,
 4;149,150,159,158;,
 3;160,161,162;,
 3;163,164,161;,
 3;165,166,164;,
 3;167,168,166;,
 3;169,170,168;,
 3;171,172,170;,
 3;173,174,172;,
 3;175,176,174;,
 4;162,161,177,178;,
 4;161,164,179,177;,
 4;164,166,180,179;,
 4;166,168,181,180;,
 4;168,170,182,181;,
 4;170,172,183,182;,
 4;172,174,184,183;,
 4;174,176,185,184;,
 4;178,177,186,187;,
 4;177,179,188,186;,
 4;179,180,189,188;,
 4;180,181,190,189;,
 4;181,182,191,190;,
 4;182,183,192,191;,
 4;183,184,193,192;,
 4;184,185,194,193;,
 4;187,186,195,196;,
 4;186,188,197,195;,
 4;188,189,198,197;,
 4;189,190,199,198;,
 4;190,191,200,199;,
 4;191,192,201,200;,
 4;192,193,202,201;,
 4;193,194,203,202;,
 4;196,195,204,205;,
 4;195,197,206,204;,
 4;197,198,207,206;,
 4;198,199,208,207;,
 4;199,200,209,208;,
 4;200,201,210,209;,
 4;201,202,211,210;,
 4;202,203,212,211;,
 4;205,204,213,214;,
 4;204,206,215,213;,
 4;206,207,216,215;,
 4;207,208,217,216;,
 4;208,209,218,217;,
 4;209,210,219,218;,
 4;210,211,220,219;,
 4;211,212,221,220;,
 4;214,213,222,223;,
 4;213,215,224,222;,
 4;215,216,225,224;,
 4;216,217,226,225;,
 4;217,218,227,226;,
 4;218,219,228,227;,
 4;219,220,229,228;,
 4;220,221,230,229;,
 4;223,222,231,232;,
 4;222,224,233,231;,
 4;224,225,234,233;,
 4;225,226,235,234;,
 4;226,227,236,235;,
 4;227,228,237,236;,
 4;228,229,238,237;,
 4;229,230,239,238;,
 3;232,231,240;,
 3;231,233,241;,
 3;233,234,242;,
 3;234,235,243;,
 3;235,236,244;,
 3;236,237,245;,
 3;237,238,246;,
 3;238,239,247;;
 
 MeshMaterialList {
  5;
  199;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  3,
  1,
  1,
  3,
  3,
  1,
  1,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.542400;0.542400;0.542400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.279200;0.279200;0.279200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.517600;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  211;
  -0.000000;1.000000;-0.000000;,
  0.000000;0.945768;-0.324843;,
  0.229699;0.945768;-0.229699;,
  0.324842;0.945768;-0.000001;,
  0.229698;0.945768;0.229699;,
  0.000000;0.945768;0.324843;,
  -0.229697;0.945769;0.229698;,
  -0.324840;0.945769;-0.000001;,
  -0.229698;0.945768;-0.229699;,
  0.017995;0.680564;-0.732468;,
  0.539105;0.648227;-0.537743;,
  0.746409;0.665068;-0.023616;,
  0.497851;0.710698;0.497044;,
  0.000001;0.723507;0.690317;,
  -0.497850;0.710699;0.497044;,
  -0.735344;0.677668;-0.005905;,
  -0.515476;0.687598;-0.511365;,
  -0.089594;0.397770;-0.913100;,
  0.725857;0.366257;-0.582226;,
  0.940180;0.335315;-0.060206;,
  0.648393;0.359906;0.670861;,
  0.001779;0.344107;0.938929;,
  -0.646446;0.363964;0.670550;,
  -0.940986;0.337636;-0.023400;,
  -0.650399;0.343860;-0.677305;,
  -0.095078;0.163510;-0.981950;,
  0.739027;0.209433;-0.640294;,
  0.980899;0.188118;-0.049476;,
  0.679205;0.130256;0.722298;,
  0.003285;0.086742;0.996225;,
  -0.677319;0.132388;0.723680;,
  -0.985841;0.165543;-0.026692;,
  -0.659781;0.158541;-0.734543;,
  0.011933;-0.155115;-0.987824;,
  0.671797;-0.167162;-0.721627;,
  0.980763;-0.194642;-0.014769;,
  0.677547;-0.196183;0.708832;,
  0.001694;-0.175949;0.984398;,
  -0.676361;-0.198495;0.709320;,
  -0.979775;-0.199840;-0.010280;,
  -0.664886;-0.181791;-0.724485;,
  0.000000;-0.858204;-0.513310;,
  0.338416;-0.873389;-0.350237;,
  0.476137;-0.879371;0.000000;,
  0.338449;-0.874494;0.347437;,
  0.000000;-0.861593;0.507600;,
  -0.338449;-0.874494;0.347438;,
  -0.476138;-0.879371;0.000000;,
  -0.338416;-0.873389;-0.350238;,
  0.000000;-0.999856;-0.016943;,
  0.012592;-0.999849;-0.011980;,
  0.017808;-0.999841;0.000000;,
  0.012592;-0.999849;0.011980;,
  0.000000;-0.999856;0.016942;,
  -0.012592;-0.999849;0.011980;,
  -0.017807;-0.999841;0.000000;,
  -0.012592;-0.999849;-0.011980;,
  -0.000000;-1.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.698873;0.715246;0.000000;,
  0.000001;1.000000;0.000000;,
  0.698875;0.715244;0.000000;,
  1.000000;0.000000;-0.000000;,
  0.698865;-0.715253;0.000000;,
  0.000001;-1.000000;0.000000;,
  -0.698864;-0.715255;0.000000;,
  -0.756837;0.003137;0.653596;,
  -0.514774;0.593126;0.619039;,
  0.155959;0.983692;-0.089598;,
  0.591858;0.683875;-0.426637;,
  0.722394;-0.000809;-0.691481;,
  0.416613;-0.729114;-0.542979;,
  -0.036036;-0.984916;-0.169239;,
  -0.640298;-0.583039;0.500084;,
  -0.000001;0.006949;0.999976;,
  -0.000001;0.447431;0.894318;,
  -0.000000;0.506078;0.862488;,
  0.495743;0.661341;-0.562909;,
  0.000001;-0.001666;-0.999999;,
  0.000001;-0.674741;-0.738055;,
  0.000000;-0.884218;-0.467074;,
  -0.576311;-0.454219;0.679375;,
  0.756836;0.003136;0.653597;,
  0.514772;0.593127;0.619039;,
  0.334176;0.769005;0.544939;,
  -0.591856;0.683878;-0.426636;,
  -0.722394;-0.000808;-0.691482;,
  -0.416611;-0.729116;-0.542978;,
  0.036035;-0.984916;-0.169240;,
  0.640297;-0.583039;0.500085;,
  1.000000;0.000000;-0.000000;,
  0.698873;0.715246;0.000000;,
  -0.000003;1.000000;0.000000;,
  -0.698873;0.715246;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.698863;-0.715255;0.000000;,
  -0.000003;-1.000000;0.000000;,
  0.698863;-0.715255;0.000000;,
  0.759921;0.003577;-0.650006;,
  0.489785;0.633108;-0.599403;,
  -0.092143;0.983193;-0.157612;,
  -0.603460;0.679244;0.417688;,
  -0.729951;-0.001317;0.683498;,
  -0.416832;-0.729043;0.542906;,
  0.196666;-0.980455;-0.005583;,
  0.643265;-0.610772;-0.461701;,
  0.234783;0.145507;-0.961095;,
  -0.000001;0.519739;-0.854325;,
  -0.000000;0.636535;-0.771248;,
  -0.521268;0.655126;0.546891;,
  -0.195959;-0.137717;0.970893;,
  0.000001;-0.674539;0.738239;,
  0.000002;-0.882739;0.469864;,
  0.593047;-0.516246;-0.617888;,
  -0.759921;0.003578;-0.650005;,
  -0.489787;0.633107;-0.599403;,
  -0.054605;0.953460;-0.296534;,
  0.603461;0.679243;0.417687;,
  0.729953;-0.001318;0.683497;,
  0.416832;-0.729043;0.542907;,
  -0.040401;-0.984591;0.170142;,
  -0.643266;-0.610772;-0.461700;,
  0.000001;1.000000;0.000000;,
  0.000001;0.940247;-0.340493;,
  0.240766;0.940247;-0.240765;,
  0.340494;0.940247;0.000000;,
  0.240765;0.940247;0.240766;,
  0.000000;0.940247;0.340493;,
  -0.240764;0.940247;0.240766;,
  -0.340492;0.940247;0.000000;,
  -0.240764;0.940247;-0.240766;,
  0.000001;0.752329;-0.658787;,
  0.453108;0.761819;-0.462953;,
  0.640966;0.767570;0.000000;,
  0.453231;0.767569;0.453231;,
  0.000000;0.767569;0.640966;,
  -0.453231;0.767569;0.453233;,
  -0.640965;0.767570;0.000001;,
  -0.453106;0.761819;-0.462954;,
  0.000001;0.458062;-0.888920;,
  0.601289;0.486539;-0.633822;,
  0.865029;0.501721;0.000001;,
  0.611668;0.501722;0.611668;,
  0.000000;0.501722;0.865029;,
  -0.611668;0.501722;0.611668;,
  -0.865029;0.501721;0.000001;,
  -0.601288;0.486540;-0.633824;,
  0.000001;0.151524;-0.988454;,
  0.671953;0.167265;-0.721458;,
  0.984675;0.174398;0.000000;,
  0.696271;0.174399;0.696270;,
  0.000000;0.174400;0.984675;,
  -0.696271;0.174399;0.696270;,
  -0.984675;0.174398;0.000000;,
  -0.671952;0.167265;-0.721459;,
  0.000001;-0.181236;-0.983440;,
  0.668188;-0.183383;-0.721038;,
  0.984676;-0.174396;0.000000;,
  0.687073;-0.218150;0.693066;,
  0.000000;-0.257840;0.966188;,
  -0.687073;-0.218150;0.693066;,
  -0.984676;-0.174396;0.000000;,
  -0.668187;-0.183383;-0.721039;,
  0.090371;-0.624787;-0.775548;,
  0.633423;-0.361072;-0.684399;,
  0.939694;-0.342016;0.000000;,
  0.634019;-0.425532;0.645710;,
  0.087911;-0.700451;0.708266;,
  -0.509114;-0.706180;0.492049;,
  -0.939694;-0.342016;0.000000;,
  -0.633422;-0.361073;-0.684399;,
  0.073608;-0.993158;0.090655;,
  -0.265369;-0.962071;0.063241;,
  -0.384548;-0.923105;-0.000000;,
  -0.265369;-0.962071;-0.063241;,
  0.073609;-0.993158;-0.090655;,
  0.258388;-0.964036;-0.062214;,
  0.228729;-0.973490;-0.000000;,
  0.258387;-0.964036;0.062214;,
  0.076994;-0.994710;0.068003;,
  -0.102529;-0.994710;-0.006358;,
  -0.205991;-0.978554;-0.000000;,
  -0.102529;-0.994710;0.006358;,
  0.076995;-0.994710;-0.068003;,
  0.210048;-0.969977;-0.122577;,
  0.266018;-0.963968;-0.000000;,
  0.210047;-0.969977;0.122577;,
  0.000000;-1.000000;0.000000;,
  -0.232467;0.492214;0.838859;,
  0.000000;0.962434;-0.271516;,
  -0.561666;-0.555448;0.613195;,
  -0.495743;0.661344;-0.562907;,
  -0.403241;0.892673;-0.201325;,
  0.561665;-0.555444;0.613200;,
  0.576310;-0.454220;0.679375;,
  0.000000;0.965646;0.259861;,
  0.564900;-0.666742;-0.486152;,
  0.521269;0.655126;0.546890;,
  0.451454;0.861640;0.231874;,
  0.514584;0.352468;0.781646;,
  -0.564900;-0.666746;-0.486147;,
  -0.593048;-0.516245;-0.617888;,
  -0.597000;-0.344683;-0.724420;,
  -0.257744;-0.934348;0.246093;,
  -0.298492;-0.947659;0.113332;,
  -0.333508;-0.942747;0.000000;,
  -0.298491;-0.947659;-0.113333;,
  -0.257743;-0.934348;-0.246093;,
  0.235900;-0.942494;0.236761;,
  -0.110475;-0.993879;0.000000;,
  0.064055;-0.987483;-0.144129;;
  199;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,33,41,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;,
  4;58,59,67,66;,
  4;59,60,68,67;,
  4;60,61,69,68;,
  4;61,62,70,69;,
  4;62,63,71,70;,
  4;63,64,72,71;,
  4;64,65,73,72;,
  4;65,58,66,73;,
  4;66,67,75,74;,
  4;67,188,76,75;,
  4;68,69,77,189;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;190,73,81,190;,
  4;73,66,74,81;,
  4;74,75,83,82;,
  4;75,76,84,83;,
  4;189,191,85,192;,
  4;191,78,86,85;,
  4;78,79,87,86;,
  4;79,80,88,87;,
  4;193,194,89,193;,
  4;194,74,82,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;192,85,93,92;,
  4;85,86,94,93;,
  4;86,87,95,94;,
  4;87,88,96,95;,
  4;88,89,97,96;,
  4;89,82,90,97;,
  4;90,91,99,98;,
  4;91,92,100,99;,
  4;92,93,101,100;,
  4;93,94,102,101;,
  4;94,95,103,102;,
  4;95,96,104,103;,
  4;96,97,105,104;,
  4;97,90,98,105;,
  4;98,99,107,106;,
  4;99,100,108,107;,
  4;100,101,109,195;,
  4;101,102,110,109;,
  4;102,103,111,110;,
  4;103,104,112,111;,
  4;104,105,113,196;,
  4;105,98,106,113;,
  4;106,107,115,114;,
  4;107,108,116,115;,
  4;195,197,117,198;,
  4;197,199,118,117;,
  4;110,111,119,118;,
  4;111,112,120,119;,
  4;200,201,121,200;,
  4;201,202,114,121;,
  4;114,115,59,58;,
  4;115,116,60,59;,
  4;116,117,61,60;,
  4;117,118,62,61;,
  4;118,119,63,62;,
  4;119,120,64,63;,
  4;120,121,65,64;,
  4;121,114,58,65;,
  3;122,124,123;,
  3;122,125,124;,
  3;122,126,125;,
  3;122,127,126;,
  3;122,128,127;,
  3;122,129,128;,
  3;122,130,129;,
  3;122,123,130;,
  4;123,124,132,131;,
  4;124,125,133,132;,
  4;125,126,134,133;,
  4;126,127,135,134;,
  4;127,128,136,135;,
  4;128,129,137,136;,
  4;129,130,138,137;,
  4;130,123,131,138;,
  4;131,132,140,139;,
  4;132,133,141,140;,
  4;133,134,142,141;,
  4;134,135,143,142;,
  4;135,136,144,143;,
  4;136,137,145,144;,
  4;137,138,146,145;,
  4;138,131,139,146;,
  4;139,140,148,147;,
  4;140,141,149,148;,
  4;141,142,150,149;,
  4;142,143,151,150;,
  4;143,144,152,151;,
  4;144,145,153,152;,
  4;145,146,154,153;,
  4;146,139,147,154;,
  4;147,148,156,155;,
  4;148,149,157,156;,
  4;149,150,158,157;,
  4;150,151,159,158;,
  4;151,152,160,159;,
  4;152,153,161,160;,
  4;153,154,162,161;,
  4;154,147,155,162;,
  4;155,156,164,163;,
  4;156,157,165,164;,
  4;157,158,166,165;,
  4;158,159,167,166;,
  4;159,160,168,167;,
  4;160,161,169,168;,
  4;161,162,170,169;,
  4;162,155,163,170;,
  4;203,204,172,171;,
  4;204,205,173,172;,
  4;205,206,174,173;,
  4;206,207,175,174;,
  4;167,208,176,175;,
  4;168,209,177,176;,
  4;209,210,178,177;,
  4;210,163,171,178;,
  4;171,172,180,179;,
  4;172,173,181,180;,
  4;173,174,182,181;,
  4;174,175,183,182;,
  4;175,176,184,183;,
  4;176,177,185,184;,
  4;177,178,186,185;,
  4;178,171,179,186;,
  3;179,180,187;,
  3;180,181,187;,
  3;181,182,187;,
  3;182,183,187;,
  3;183,184,187;,
  3;184,185,187;,
  3;185,186,187;,
  3;186,179,187;;
 }
 MeshTextureCoords {
  248;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.250000;0.500000;,
  0.125000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.000000;0.125000;,
  0.125000;0.125000;,
  0.125000;0.000000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.000000;0.375000;,
  0.125000;0.375000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.000000;0.625000;,
  0.125000;0.625000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.000000;0.875000;,
  0.125000;0.875000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.250000;0.375000;,
  0.250000;0.500000;,
  0.250000;0.625000;,
  0.250000;0.750000;,
  0.250000;0.875000;,
  0.250000;1.000000;,
  0.375000;0.125000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.375000;1.000000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.500000;0.375000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.500000;1.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  0.750000;0.375000;,
  0.750000;0.500000;,
  0.750000;0.625000;,
  0.750000;0.750000;,
  0.750000;0.875000;,
  0.750000;1.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.875000;0.375000;,
  0.875000;0.500000;,
  0.875000;0.625000;,
  0.875000;0.750000;,
  0.875000;0.875000;,
  0.875000;1.000000;,
  1.000000;0.125000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  1.000000;0.375000;,
  1.000000;0.500000;,
  1.000000;0.625000;,
  1.000000;0.750000;,
  1.000000;0.875000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.111110;,
  0.000000;0.111110;,
  0.187500;0.000000;,
  0.250000;0.111110;,
  0.312500;0.000000;,
  0.375000;0.111110;,
  0.437500;0.000000;,
  0.500000;0.111110;,
  0.562500;0.000000;,
  0.625000;0.111110;,
  0.687500;0.000000;,
  0.750000;0.111110;,
  0.812500;0.000000;,
  0.875000;0.111110;,
  0.937500;0.000000;,
  1.000000;0.111110;,
  0.125000;0.222220;,
  0.000000;0.222220;,
  0.250000;0.222220;,
  0.375000;0.222220;,
  0.500000;0.222220;,
  0.625000;0.222220;,
  0.750000;0.222220;,
  0.875000;0.222220;,
  1.000000;0.222220;,
  0.125000;0.333330;,
  0.000000;0.333330;,
  0.250000;0.333330;,
  0.375000;0.333330;,
  0.500000;0.333330;,
  0.625000;0.333330;,
  0.750000;0.333330;,
  0.875000;0.333330;,
  1.000000;0.333330;,
  0.125000;0.444440;,
  0.000000;0.444440;,
  0.250000;0.444440;,
  0.375000;0.444440;,
  0.500000;0.444440;,
  0.625000;0.444440;,
  0.750000;0.444440;,
  0.875000;0.444440;,
  1.000000;0.444440;,
  0.125000;0.555560;,
  0.000000;0.555560;,
  0.250000;0.555560;,
  0.375000;0.555560;,
  0.500000;0.555560;,
  0.625000;0.555560;,
  0.750000;0.555560;,
  0.875000;0.555560;,
  1.000000;0.555560;,
  0.125000;0.666670;,
  0.000000;0.666670;,
  0.250000;0.666670;,
  0.375000;0.666670;,
  0.500000;0.666670;,
  0.625000;0.666670;,
  0.750000;0.666670;,
  0.875000;0.666670;,
  1.000000;0.666670;,
  0.125000;0.777780;,
  0.000000;0.777780;,
  0.250000;0.777780;,
  0.375000;0.777780;,
  0.500000;0.777780;,
  0.625000;0.777780;,
  0.750000;0.777780;,
  0.875000;0.777780;,
  1.000000;0.777780;,
  0.125000;0.888890;,
  0.000000;0.888890;,
  0.250000;0.888890;,
  0.375000;0.888890;,
  0.500000;0.888890;,
  0.625000;0.888890;,
  0.750000;0.888890;,
  0.875000;0.888890;,
  1.000000;0.888890;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
