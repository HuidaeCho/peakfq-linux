character(len=256) :: specfile

if(command_argument_count().eq.0) then
  write(*,*) "Usage: peakfq specfile"
else
  call get_command_argument(1, specfile)
  call peakfq(specfile)
endif
end
