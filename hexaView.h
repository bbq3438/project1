#pragma once

//////////////////////////////////////////////////////////////////////////
// Product Date : 2009/09/18                                            //
// Author : (Last) Lee                                                  //
//          (First) Hyunbin                                             //
// comment : This function is printed hexa and ascii code               //
//           입력되는 버퍼의 내용을 hexa(16진수)와                      //
//           아스키 코드(ascii code)로 출력 시키는 함수                 //
// 인지값 - INPUT : 포인터의 방향을 표시, 즉 입력이란 의미              //
//		    const : 입력된 버퍼의 값은 함수 실행 도중에 변경되지 않음   //
//          u_char *buffer : unsigned char pointer 형 변수 buffer       //
// 반환값 - void                                                        //
//////////////////////////////////////////////////////////////////////////
void hexaView(const unsigned char *buffer, int size);