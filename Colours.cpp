//
//  Colours.cpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 07/02/17.
//
//

#include "Colours.hpp"
Colours::Colours()
{
    

}
ofColor Colours::complementaryCol(ofColor col1)
{
    
    
    
    
    r = col1.r;
    g = col1.g;
    b = col1.b;
    
    
    
    r = r/255;
    g = g/255;
    b = b/255;
    
    float diff = cMax-cMin;
    float deg = 60.0;
    float rad = ofDegToRad(deg);
    
    
    
    
    
    
    
    
    
    
    
    //calculating hue
    if (r>g && r>b) {
        cMax = r;
        _h = rad*(((g-b)/diff));
    } else if (g>r && g>b) {
        cMax = g;
        _h = rad*(((b-r)/diff)+2);
    } else if (b>r && b>r) {
        cMax = b;
        _h = rad*(((r-g)/diff)+4);
    }
    
    
    
    if (r<g && r<b) {
        cMin = r;
    } else if (g<r && g<b) {
        cMin = g;
    } else if (b<r && b<r) {
        cMin = b;
    }
    
    
    
    
    
    
    
    
    
    
    
    // calculating saturation
    if (cMax==0) {
        _s = 0;
    } else if (cMax >0) {
        _s = diff/cMax;
        
    }
    
    
    
    //calculating brightness
    _l = (cMax-cMin)/2;
     
    _h = ofRadToDeg(_h);
    
    _h = _h+180;
    
    
    
//    cout<<"Hue"<<_h<<endl;
//    cout<<"Lightness"<<_l<<endl;
//    cout<<"Saturation"<<_s<<endl;
    
    
    
    
    if ( _s == 0.00 )                       //HSL from 0 to 1
    {
        
        
        r = _l * 255;                      //RGB results from 0 to 255
        g = _l * 255;
        b = _l * 255;
        
        
    }
    
    else
    {
        
        
        if ( _l < 0.5 ){
            
            temp1 = _l * ( 1 + _s );

            
        }
        
        else {
            
            temp1 = ( _l + _s ) - ( _s * _l );
            
        }
        
        
        
        
        temp2 = 2 * _l - temp1;
        
        
        _h = _h/360;
        
        
        
        
        
        
        
        tempR = _h +0.333;
        
        tempG = _h;
        
        tempB = _h - 0.333;
        
        
        
        
        if(tempR>1){
            tempR -= 1;
            
        }
        if(tempG>1){
            tempG -= 1;
            
        }
        if(tempB>1){
            tempB -= 1;
            
        }
        
        if(tempR<0){
            tempR += 1;
            
        }
        if(tempG<0){
            tempG += 1;
            
        }
        if(tempB<0){
            tempB += 1;
            
        }
        
        
        ///red
        if(6*tempR<1){
            
            
            _r = temp2 + (temp1 - temp2)*6*tempR;
            
        }
        
        else if(2*tempR<1){
            _r = temp1;
        }
        else if(3*tempR<2){
            
            _r = temp2+(temp1-temp2)*(0.666-tempR)*6;
            
        }
        else{
            
            _r - temp2;
            
            
        }
        
        
        
        
        
        
        ///red
        if(6*tempB<1){
            
            
            _b = temp2 + (temp1 - temp2)*6*tempB;
            
        }
        
        else if(2*tempB<1){
            _b = temp1;
        }
        else if(3*tempB<2){
            
            _b = temp2+(temp1-temp2)*(0.666-tempB)*6;
            
        }
        else{
            
            _b - temp2;
            
            
        }
        
        
        
        
        
        ///red
        if(6*tempG<1){
            
            
            _g = temp2 + (temp1 - temp2)*6*tempG;
            
        }
        
        else if(2*tempG<1){
            _g = temp1;
        }
        else if(3*tempG<2){
            
            _g = temp2+(temp1-temp2)*(0.666-tempG)*6;
            
        }
        else{
            
            _g - temp2;
            
            
        }
        
        
    }

    
    
    
    col2.r = _r*255;
    col2.g = _g*255;
    col2.b = _b*255;
    
    
    
    
    
    
    
    
    
    
    return col2;
    
    
    
}

ofColor Colours::tertiaryCol(ofColor col1)
{
        
        
        
        
        r = col1.r;
        g = col1.g;
        b = col1.b;
        
        
        
        r = r/255;
        g = g/255;
        b = b/255;
        
        float diff = cMax-cMin;
        float deg = 60.0;
        float rad = ofDegToRad(deg);
        
        
        
        
        
        
        
        
        
        
        
        //calculating hue
        if (r>g && r>b) {
            cMax = r;
            _h = rad*(((g-b)/diff));
        } else if (g>r && g>b) {
            cMax = g;
            _h = rad*(((b-r)/diff)+2);
        } else if (b>r && b>r) {
            cMax = b;
            _h = rad*(((r-g)/diff)+4);
        }
        
        if (r<g && r<b) {
            cMin = r;
        } else if (g<r && g<b) {
            cMin = g;
        } else if (b<r && b<r) {
            cMin = b;
        }
        
        
        
        
        
        
        
        
        
        
        
        // calculating saturation
        if (cMax==0) {
            _s = 0;
        } else if (cMax >0) {
            _s = diff/cMax;
            
        }
        
        
        
        //calculating brightness
        _l = (cMax-cMin)/2;
        
        
        
        
        _h = ofRadToDeg(_h);
        
        _h = _h+120;
        
        
        

        
        
        
        
        if ( _s == 0.00 )                       //HSL from 0 to 1
        {
            
            
            r = _l * 255;                      //RGB results from 0 to 255
            g = _l * 255;
            b = _l * 255;
            
            
        }
        
        else
        {
            
            
            if ( _l < 0.5 ){
                
                temp1 = _l * ( 1 + _s );

                
            }
            
            else {
                
                temp1 = ( _l + _s ) - ( _s * _l );
                
            }
            
            
            
            
            temp2 = 2 * _l - temp1;
            
            
            _h = _h/360;
            
            
            
            
            
            
            
            tempR = _h +0.333;
            
            tempG = _h;
            
            tempB = _h - 0.333;
            
            
            
            
            if(tempR>1){
                tempR -= 1;
                
            }
            if(tempG>1){
                tempG -= 1;
                
            }
            if(tempB>1){
                tempB -= 1;
                
            }
            
            if(tempR<0){
                tempR += 1;
                
            }
            if(tempG<0){
                tempG += 1;
                
            }
            if(tempB<0){
                tempB += 1;
                
            }
            
            
            ///red
            if(6*tempR<1){
                
                
                _r = temp2 + (temp1 - temp2)*6*tempR;
                
            }
            
            else if(2*tempR<1){
                _r = temp1;
            }
            else if(3*tempR<2){
                
                _r = temp2+(temp1-temp2)*(0.666-tempR)*6;
                
            }
            else{
                
                _r - temp2;
                
                
            }
            
            
            
            
            
            
            ///red
            if(6*tempB<1){
                
                
                _b = temp2 + (temp1 - temp2)*6*tempB;
                
            }
            
            else if(2*tempB<1){
                _b = temp1;
            }
            else if(3*tempB<2){
                
                _b = temp2+(temp1-temp2)*(0.666-tempB)*6;
                
            }
            else{
                
                _b - temp2;
                
                
            }
            
            
            
            
            
            ///red
            if(6*tempG<1){
                
                
                _g = temp2 + (temp1 - temp2)*6*tempG;
                
            }
            
            else if(2*tempG<1){
                _g = temp1;
            }
            else if(3*tempG<2){
                
                _g = temp2+(temp1-temp2)*(0.666-tempG)*6;
                
            }
            else{
                
                _g - temp2;
                
                
            }
            
            
        }
        
        
        
        
        col2.r = _r*255;
        col2.g = _g*255;
        col2.b = _b*255;
        
        
        
        
        
        
        
        
        
        
        return col2;
        
    
    
    
    
    
}
