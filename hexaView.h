#pragma once

//////////////////////////////////////////////////////////////////////////
// Product Date : 2009/09/18                                            //
// Author : (Last) Lee                                                  //
//          (First) Hyunbin                                             //
// comment : This function is printed hexa and ascii code               //
//           �ԷµǴ� ������ ������ hexa(16����)��                      //
//           �ƽ�Ű �ڵ�(ascii code)�� ��� ��Ű�� �Լ�                 //
// ������ - INPUT : �������� ������ ǥ��, �� �Է��̶� �ǹ�              //
//		    const : �Էµ� ������ ���� �Լ� ���� ���߿� ������� ����   //
//          u_char *buffer : unsigned char pointer �� ���� buffer       //
// ��ȯ�� - void                                                        //
//////////////////////////////////////////////////////////////////////////
void hexaView(const unsigned char *buffer, int size);