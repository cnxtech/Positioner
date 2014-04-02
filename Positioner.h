//
//  Positioner.h
//  Positioner
//
//  Created by Sam McHardy on 11/11/12.
//  Copyright (c) 2012 Josephmark. All rights reserved.
//

#ifndef Positioner_Positioner_h
#define Positioner_Positioner_h


class Positioner
{
public:
    Positioner(int timesToVisit);
    
    int getNextPosition(float* pos);
    
protected: 
    void _resetPositions();   
    
private:
    int _visited[3][3];
    int _timesToVisit;
};

#endif
