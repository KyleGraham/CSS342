#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <math.h>        // for pow( )
#include <sstream>       // for stringstream
#include <vector>        // for vector
#include "tokenizer.h"

using namespace std;

// PREC_TABLE matches order of TokenType enumeration.
struct Precedence {
  int inputSymbol;
  int topOfStack;
};

template <class NumericType>
class Evaluator {
 public:
  Evaluator( const string &s ) : str( s ) { // constructor receives an exp
    opStack.push_back( EOL );

    PREC_TABLE[0].inputSymbol = 0;      // EOL
    PREC_TABLE[0].topOfStack =  -1;
    PREC_TABLE[1].inputSymbol = 0;      // VALUE
    PREC_TABLE[1].topOfStack =  0;
    PREC_TABLE[2].inputSymbol = 100;    // OPAREN 
    PREC_TABLE[2].topOfStack =  0;
    PREC_TABLE[3].inputSymbol = 99;     // CPAREN
    PREC_TABLE[3].topOfStack =  0;
    PREC_TABLE[4].inputSymbol = 16;      // EXCLUSIVE OR
    PREC_TABLE[4].topOfStack =  17;
    PREC_TABLE[5].inputSymbol = 28;      // MULT
    PREC_TABLE[5].topOfStack =  29;
    PREC_TABLE[6].inputSymbol = 28;      // DIV
    PREC_TABLE[6].topOfStack =  29;
    PREC_TABLE[7].inputSymbol = 26;      // PLUS
    PREC_TABLE[7].topOfStack =  27;
    PREC_TABLE[8].inputSymbol = 26;      // MINUS
    PREC_TABLE[8].topOfStack =  27;
	PREC_TABLE[9].inputSymbol = 28;      // MOD
    PREC_TABLE[9].topOfStack =  29;
    PREC_TABLE[10].inputSymbol = 22;      // LESS THAN
    PREC_TABLE[10].topOfStack =  23;
	PREC_TABLE[11].inputSymbol = 22;      // GREATER THAN
    PREC_TABLE[11].topOfStack =  23;
    PREC_TABLE[12].inputSymbol = 22;      // LESS THAN EQUAL TO
    PREC_TABLE[12].topOfStack =  23;
	PREC_TABLE[13].inputSymbol = 22;      // GREATER THAN EQUAL TO
    PREC_TABLE[13].topOfStack =  23;
    PREC_TABLE[14].inputSymbol = 24;      // LEFT SHIFT
    PREC_TABLE[14].topOfStack =  25;
	PREC_TABLE[15].inputSymbol = 24;      // RIGHT SHIFT
    PREC_TABLE[15].topOfStack =  25;
    PREC_TABLE[16].inputSymbol = 4;      // EQUALS
    PREC_TABLE[16].topOfStack =  5;    
	PREC_TABLE[17].inputSymbol = 20;      // IF EQUAL
    PREC_TABLE[17].topOfStack =  21;
    PREC_TABLE[18].inputSymbol = 20;      // NOT EQUAL
    PREC_TABLE[18].topOfStack =  21;
	PREC_TABLE[19].inputSymbol = 18;      // AND
    PREC_TABLE[19].topOfStack =  19;
    PREC_TABLE[20].inputSymbol = 12;      // LOGICAL AND
    PREC_TABLE[20].topOfStack =  13;    
	PREC_TABLE[21].inputSymbol = 14;      // OR
    PREC_TABLE[21].topOfStack =  15;
    PREC_TABLE[22].inputSymbol = 10;      // LOGICAL OR
    PREC_TABLE[22].topOfStack =  11;
	PREC_TABLE[23].inputSymbol = 30;      // NEGATION
    PREC_TABLE[23].topOfStack =  31;
	PREC_TABLE[24].inputSymbol = 30;      // COMPLIMENT
    PREC_TABLE[24].topOfStack =  31;
	PREC_TABLE[25].inputSymbol = 30;      // UNARY PLUS
    PREC_TABLE[25].topOfStack =  31;
	PREC_TABLE[26].inputSymbol = 30;      // UNARY MINUS
    PREC_TABLE[26].topOfStack =  31;
  }

  NumericType getValue( );                  // Do the evaluation

 private:
  vector<NumericType> postFixVarStack;
  NumericType var_a;                        // variable a
  NumericType var_b;                        // variable b
  NumericType var_c;                        // variable c
  Precedence PREC_TABLE[27];
  vector<TokenType> opStack;                // Operator stack for conversion
  vector<NumericType> postFixStack;         // Postfix machine stack
  istringstream str;                        // The character stream

  // Internal routines
  NumericType getTop( );                    // Get top of postfix stack
  void binaryOp( TokenType topOp );         // Process an operator
  void processToken( const Token<NumericType> &lastToken );
};

#include "evaluator.cpp.h"
#endif