# dbus-pkdbus
qt dbus test pro


/usr/share/dbus-1/system-services/com.emindsoft.pkdbus.service

[D-BUS Service]
Name=com.emindsoft.pkdbus
Exec=/usr/bin/pkdbus
User=root




/usr/share/dbus-1/services/com.emindsoft.pkdbus.conf

<?xml version="1.0" encoding="UTF-8"?> <!-- -*- XML -*- -->

<!DOCTYPE busconfig PUBLIC
 "-//freedesktop//DTD D-BUS Bus Configuration 1.0//EN"
 "http://www.freedesktop.org/standards/dbus/1.0/busconfig.dtd">
<busconfig>

  <!-- Only root can own the service -->
  <policy user="root">
    <allow own="com.emindsoft.pkdbus"/>
  </policy>


  <!-- Allow anyone to invoke methods on the interfaces -->
  <policy context="default">
      <allow send_interface="com.emindsoft.pkdbus.registry"/>
      <allow receive_sender="com.emindsoft.pkdbus.registry"/>
      <allow receive_interface="com.emindsoft.pkdbus.registry"/>
  </policy>

</busconfig>