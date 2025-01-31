-----
entity HALF_ADDER is
    port (A,B: in BIT;
    SUM, CRY: out BIT);
    end HALF_ADDER;
    --Body --Use components in Package gates
----->                      <-----
        Use WORK.gates.all; OR 
        Use WORK.gates.and_2; 
----->                      <------
        --------------------
    Architecture structural of HALF_ADDER is
    Begin
    X1: xor_2 port map(A,B,SUM);
    A1: and_2 port map(A,B, CRY);
    end structural;
 ---------   