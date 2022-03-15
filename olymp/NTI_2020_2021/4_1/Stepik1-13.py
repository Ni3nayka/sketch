
while (1):
  if (brick.sensor(D1).read() > 35):
    brick.motor(M3).setPower(100)
    brick.motor(M4).setPower(-(100))
    script.wait(30)
    brick.motor(M4).setPower(100)
    brick.motor(M3).setPower(100)
    script.wait(100)
  else:
    brick.motor(M4).setPower(100)
    brick.motor(M3).setPower(-(100))
    script.wait(30)
    brick.motor(M4).setPower(100)
    brick.motor(M3).setPower(100)
    script.wait(100)
