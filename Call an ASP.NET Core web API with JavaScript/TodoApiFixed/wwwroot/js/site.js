const uri = "api/todoitems";
let todos = [];

function getItems() {
  fetch(uri)
    .then((response) => response.json())
    .then((data) => _displayItems(data))
    .catch((error) => console.error("Unable to get items.", error));
}

function addItem() {
  const addNameTextbox = document.getElementById("add-name");
  const addIsCompleteCheckbox = document.getElementById("add-isComplete");
  const addCompletionDateTextbox =
    document.getElementById("add-completionDate");

  const item = {
    name: addNameTextbox.value.trim(),
    isComplete: addIsCompleteCheckbox.checked,
    completionDate: addCompletionDateTextbox.value.trim(),
  };

  fetch(uri, {
    method: "POST",
    headers: {
      Accept: "application/json",
      "Content-Type": "application/json",
    },
    body: JSON.stringify(item),
  })
    .then((response) => response.json())
    .then(() => {
      getItems();
      addNameTextbox.value = "";
      addIsCompleteCheckbox.checked = false;
      addCompletionDateTextbox.value = "";
    })
    .catch((error) => console.error("Unable to add item.", error));
}

function deleteItem(id) {
  fetch(`${uri}/${id}`, {
    method: "DELETE",
  })
    .then(() => getItems())
    .catch((error) => console.error("Unable to delete item.", error));
}

function displayEditForm(id) {
  const item = todos.find((item) => item.id === id);

  document.getElementById("edit-id").value = item.id;
  document.getElementById("edit-name").value = item.name;
  document.getElementById("edit-isComplete").checked = item.isComplete;
  document.getElementById("edit-completionDate").value =
    item.completionDate || "";

  document.getElementById("editForm").style.display = "block";
}

function updateItem() {
  const itemId = document.getElementById("edit-id").value;

  const item = {
    id: parseInt(itemId),
    name: document.getElementById("edit-name").value.trim(),
    isComplete: document.getElementById("edit-isComplete").checked,
    completionDate: document.getElementById("edit-completionDate").value.trim(),
  };

  fetch(`${uri}/${itemId}`, {
    method: "PUT",
    headers: {
      Accept: "application/json",
      "Content-Type": "application/json",
    },
    body: JSON.stringify(item),
  })
    .then(() => getItems())
    .catch((error) => console.error("Unable to update item.", error));

  closeInput();

  return false;
}

function closeInput() {
  document.getElementById("editForm").style.display = "none";
}

function _displayCount(itemCount) {
  const name = itemCount === 1 ? "to-do" : "to-dos";

  document.getElementById("counter").innerText = `${itemCount} ${name}`;
}

function _displayItems(data) {
  const tBody = document.getElementById("todos");
  tBody.innerHTML = "";

  _displayCount(data.length);

  const button = document.createElement("button");

  data.forEach((item) => {
    const editButton = button.cloneNode(false);
    editButton.innerText = "Edit";
    editButton.setAttribute("onclick", `displayEditForm(${item.id})`);

    const deleteButton = button.cloneNode(false);
    deleteButton.innerText = "Delete";
    deleteButton.setAttribute("onclick", `deleteItem(${item.id})`);

    const tr = tBody.insertRow();

    let td1 = tr.insertCell(0);
    td1.appendChild(document.createTextNode(item.id));

    let td2 = tr.insertCell(1);
    let checkbox = document.createElement("input");
    checkbox.type = "checkbox";
    checkbox.disabled = true;
    checkbox.checked = item.isComplete;
    td2.appendChild(checkbox);

    let td3 = tr.insertCell(2);
    td3.appendChild(document.createTextNode(item.completionDate || ""));

    let td4 = tr.insertCell(3);
    td4.appendChild(document.createTextNode(item.name));

    let td5 = tr.insertCell(4);
    td5.appendChild(editButton);
    td5.appendChild(document.createTextNode(" "));
    td5.appendChild(deleteButton);
  });

  todos = data;
}

getItems();
