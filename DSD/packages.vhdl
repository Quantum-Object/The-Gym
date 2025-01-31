--Package Description
Package gates is
    --Declare all the gates component
    and_2 is
    Port (A,B: in BIT;
    Z: out BIT);
    end component;
    Component xor_2 is
    port (A,B: in BIT;
    Z: out BIT);
    End component;
    Component or_2 is
    port (A,B: in BIT; Z: outBIT);
    End component;
    End gates;
