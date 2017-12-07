# dbus-pkdbus
qt-dbus test project

1.
/usr/share/dbus-1/system-services/com.emindsoft.pkdbus.service          // 自动调起服务

[D-BUS Service]
Name=com.emindsoft.pkdbus
Exec=/usr/bin/pkdbus
User=root



2.
/usr/share/dbus-1/services/com.emindsoft.pkdbus.conf          //

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

3.
// qdbuscpp2xml -M -S pkdbus.h -o com.emindsoft.pkdbus.xml
// qdbusxml2cpp com.emindsoft.pkdbus.xml -a pkdbusAdaptor
// qdbusxml2cpp com.emindsoft.pkdbus.xml -p pkdbusInterface


//加入 /usr/share/dbus-1/services/com.emindsoft.pkdbus.service   sessionBuss()可以自动调起。 systemBus注册失败。
// 目录放错了，应该放到/usr/share/dbus-1/system-services里


4.
How to monitor the session bus
This one is easy. Just run dbus-monitor and watch the output. This usually gives you enough information about what is happening on the bus.


How to monitor the system bus      //   systemBus 有error提示， 并且看不到注册信息，用此方法可以看到，调试时可以使用
This is trickier, because D-Bus policy typically prevents anything but signals from being viewable by dbus-monitor. But we can change that.

Create a file /etc/dbus-1/system-local.conf, with these contents:
<!DOCTYPE busconfig PUBLIC
"-//freedesktop//DTD D-Bus Bus Configuration 1.0//EN"
"http://www.freedesktop.org/standards/dbus/1.0/busconfig.dtd">
<busconfig>
    <policy user="root">
        <allow eavesdrop="true"/>
        <allow eavesdrop="true" send_destination="*"/>
    </policy>
</busconfig>

Reboot your machine to pick up the configuration changes. Simply reloading the DBus server configuration is not sufficient. For further info see this bug.

Now run dbus-monitor as root. You should be able to see all signals, method calls, and method replies.
sudo dbus-monitor --system
When done debugging, it is wise to remove the policy snippet:
sudo rm /etc/dbus-1/system-local.conf

