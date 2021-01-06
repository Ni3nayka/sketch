var __interpretation_started_timestamp__;
var pi = 3.1415926535897931;

var main = function()
{
	__interpretation_started_timestamp__ = Date.now();
	
	while (true) {
		if (brick.sensor(D1).read() > 35) {
			brick.motor(M3).setPower(100);
			
			brick.motor(M4).setPower(-(100));
			
			script.wait(30);
			
			brick.motor(M4).setPower(100);
			brick.motor(M3).setPower(100);
			
			script.wait(100);
			
		} else {
			brick.motor(M4).setPower(100);
			
			brick.motor(M3).setPower(-(100));
			
			script.wait(30);
			
			brick.motor(M4).setPower(100);
			brick.motor(M3).setPower(100);
			
			script.wait(100);
			
		}
	}
}
