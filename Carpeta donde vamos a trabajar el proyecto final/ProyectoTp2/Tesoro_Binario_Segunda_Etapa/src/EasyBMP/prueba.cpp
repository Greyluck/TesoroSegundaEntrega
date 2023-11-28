// /*************************************************
// *                                                *
// *  EasyBMP Cross-Platform Windows Bitmap Library * 
// *                                                *
// *  Author: Paul Macklin                          *
// *   email: macklin01@users.sourceforge.net       *
// * support: http://easybmp.sourceforge.net        *
// *                                                *
// *          file: EasyBMPsample.cpp               * 
// *    date added: 03-31-2006                      *
// * date modified: 12-01-2006                      *
// *       version: 1.06                            *
// *                                                *
// *   License: BSD (revised/modified)              *
// * Copyright: 2005-6 by the EasyBMP Project       * 
// *                                                *
// * description: Sample application to demonstrate *
// *              some functions and capabilities   *
// *                                                *
// *************************************************/

// #include "EasyBMP.h"
// using namespace std;

// int main( int argc, char* argv[] )
// {
//         cout << endl
//         << "Using EasyBMP Version " << _EasyBMP_Version_ << endl << endl
//         << "Copyright (c) by the EasyBMP Project 2005-6" << endl
//         << "WWW: http://easybmp.sourceforge.net" << endl << endl;

        
//         BMP Tablero3d;
//         // Tablero3d.ReadFromFile("bitmaps/cofre.bmp");

//         BMP Output;
//         Output.SetSize(100, 100);
//         Output.SetBitDepth(24);

        // int x = 0;
        // int y = 0;

        // cout << Tablero3d.TellWidth()-1 << " " << Tablero3d.TellHeight()-1 << endl;

        // RangedPixelToPixelCopy(Tablero3d, 0, Tablero3d.TellWidth()-1, Tablero3d.TellHeight()-1, 0, Output, x, y);
        // Output.WriteToFile("bitmaps/Tablero.bmp");
        // x = Tablero3d.TellWidth()-1;
        // y = 0;
        // Tablero3d.ReadFromFile("bitmaps/espia.bmp");
        // RangedPixelToPixelCopy(Tablero3d, 0, Tablero3d.TellWidth()-1, Tablero3d.TellHeight()-1, 0, Output, x, y);
        // Output.WriteToFile("bitmaps/Tablero.bmp");

        // int j = 1;
        // for(int i = 1; i < Output.TellWidth(); i = (Tablero3d.TellWidth()* (j-1))){
        //         Tablero3d.ReadFromFile("bitmaps/celda_libre.bmp");
        //         RangedPixelToPixelCopy(Tablero3d, 0, Tablero3d.TellWidth()-1, Tablero3d.TellHeight()-1, 0, Output, i-1, 0);
        //         Output.WriteToFile("bitmaps/Tablero.bmp");
        //         j++;
        // }

//         int y = 0;
//         for(int i = 1; i <= Output.TellHeight(); i = (Tablero3d.TellHeight() * y)){
//                 int x = 0;
//                 for(int j = 1; j <= Output.TellWidth(); j = (Tablero3d.TellWidth()* x)){
//                         Tablero3d.ReadFromFile("bitmaps/no_disponible.bmp");
//                         RangedPixelToPixelCopy(Tablero3d, 0, Tablero3d.TellWidth()-1, Tablero3d.TellHeight()-1, 0, Output, j-1, i-1);
//                         Output.WriteToFile("bitmaps/Tablero.bmp");
//                         x++;
//                 }
//                 y++;
//         }



// // //  BMP Text;
// // //  Text.ReadFromFile("EasyBMPtext.bmp");
  
// // //  BMP Background;
// // //  Background.ReadFromFile("EasyBMPbackground.bmp");
  
// // //  BMP Output;
// // //  Output.SetSize( Background.TellWidth() , Background.TellHeight() );
// // //  Output.SetBitDepth( 24 );
 
// // //  RangedPixelToPixelCopy( Background, 0, Output.TellWidth()-1,
// // //                          Output.TellHeight()-1 , 0, 
// // //                          Output, 0,0 );	
						 
// // //  RangedPixelToPixelCopyTransparent( Text, 0, 380, 
// // //                                     43, 0,
// // // 									Output, 110,5, 
// // // 									*Text(0,0) );

// // //  RangedPixelToPixelCopyTransparent( Text, 0, Text.TellWidth()-1, 
// // //                                     Text.TellWidth()-1, 50,
// // // 									Output, 100,442, 
// // // 									*Text(0,49) );
					
// // // //  Output.SetBitDepth( 32 );
// // // //  cout << "writing 32bpp ... " << endl;					
// // // //  Output.WriteToFile( "EasyBMPoutput32bpp.bmp" );

// // //  Output.SetBitDepth( 24 );
// // //  cout << "writing 24bpp ... " << endl;			
// // //  Output.WriteToFile( "EasyBMPoutput24bpp.bmp" );
 
// // // //  Output.SetBitDepth( 8 );
// // // //  cout << "writing 8bpp ... " << endl;					
// // // //  Output.WriteToFile( "EasyBMPoutput8bpp.bmp" );

// // // //  Output.SetBitDepth( 4 );
// // // //  cout << "writing 4bpp ... " << endl;					
// // // //  Output.WriteToFile( "EasyBMPoutput4bpp.bmp" );
 
// // // //  Output.SetBitDepth( 1 );
// // // //  cout << "writing 1bpp ... " << endl;					
// // // //  Output.WriteToFile( "EasyBMPoutput1bpp.bmp" );
 
// // // //  Output.SetBitDepth( 24 );
// // // //  Rescale( Output, 'p' , 50 );
// // // //  cout << "writing 24bpp scaled image ..." << endl;
// // // //  Output.WriteToFile( "EasyBMPoutput24bpp_rescaled.bmp" );

//  return 0;
// }
