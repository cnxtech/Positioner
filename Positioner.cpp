//
//  Positioner.cpp
//  Positioner
//
//  Created by Sam McHardy on 11/11/12.
//  Copyright (c) 2012 Josephmark. All rights reserved.
//

#include <stdlib.h>
#include "Positioner.h"
#include "Arduino.h"


Positioner::Positioner(int timesToVisit) {
    _timesToVisit = timesToVisit;
    _resetPositions();
}

/**
 *
 * Move to each position once, then move one
 * Go to closest distance position first
 *
 */ 

int Positioner::getNextPosition(float* pos) {
/*    
    Serial.print("getNextPosition(");
    Serial.print(pos[0]);
    Serial.print(", ");        
    Serial.print(pos[1]);
    Serial.print(", ");         
    Serial.print(pos[2]);  
    Serial.println(")");
*/    
    int i = 0;
    if (pos[2] <= pos[1] && pos[2] <= pos[0]) {
        i = 2;
    } else if (pos[1] <= pos[0] && pos[1] <= pos[2]) {
        i = 1;
    }
//    Serial.print("i=");
//    Serial.println(i);
    
    // can we move to this x position?
    if (_visited[i][0] + _visited[i][1] + _visited[i][2] == 3 * _timesToVisit) {
        pos[i] = 500.0;
//        Serial.println("Trying next x pos");
        getNextPosition(pos);
    } else {
        // we have a position to move to
        int j = 0;

        do {
            j = rand() % 3;    
        
        } while (_visited[i][j] == _timesToVisit);
/*        
        Serial.print("Visiting x:");
        Serial.print(i);
        Serial.print(" y:");
        Serial.println(j);
*/        
        // set this as visited
        _visited[i][j]++;
        
        // check if we need to reset all positions
        if (_visited[0][0] + _visited[0][1] + _visited[0][2] +
            _visited[1][0] + _visited[1][1] + _visited[1][2] +
            _visited[2][0] + _visited[2][1] + _visited[2][2] == 9 * _timesToVisit) {
            Serial.println("Visited all positions - reset");
            _resetPositions();
        }
        
        return i * 3 + j;
    }    
}
    
void Positioner::_resetPositions() {
        
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _visited[i][j] = 0;
        }
    }

}
