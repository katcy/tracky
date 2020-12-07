const app = require("express")();
const httpServer = require("http").createServer(app);
const socket = require("socket.io")(httpServer);

let port = process.env.PORT || 5000;

app.get("/", (req, res) => {
  res.send("Hello World");
});

socket.on("connect", (client) => {
  client.on("message", (data) => {
    console.log(data);
    socket.emit("message", data);
  });
});

app.listen(port, () => {
  console.log(`Server has started at ${port}`);
});
