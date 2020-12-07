const app = require("express")();
const httpServer = require("http").Server(app);
const socket = require("socket.io")(httpServer);

const port = process.env.PORT || 5000;

app.get("/", (req, res) => {
  console.log("html rendered");
  res.send("<h1>Hello world</h1>");
});

socket.on("connect", (client) => {
  console.log("connected");
  client.on("message", (message) => {
    console.log(message);
    socket.emit("message", message);
  });
});

httpServer.listen(port, (err) => {
  console.log(`server started at ${port}`);
});
